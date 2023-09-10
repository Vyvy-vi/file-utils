CC = g++
CFLAGS = -g -Wall -std=c++14
#CPPFLAGS = -I/opt/homebrew/include -L/opt/homebrew/lib

SRC = src
OBJ = obj
SRCS = $(shell find $(SRC) -name '*.cpp') 
OBJS = $(patsubst $(SRC)/%.cpp, $(OBJ)/%.o, $(SRCS))

BINDIR = bin
BIN = $(BINDIR)/file-utils

TEST = tests
TESTS = $(wildcard $(TEST)/*.cpp)
TESTBINS = $(patsubst $(TEST)/%.cpp, $(TEST)/bin/%, $(TESTS))

all: $(BIN)

$(BIN): $(BINDIR) $(OBJ) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.cpp $(SRC)/%.h
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.cpp
	$(CC) $(CFLAGS) $< -o $@ $(CPPFLAGS) -lcriterion

$(TEST)/bin:
	mkdir $@

$(TEST)/inputs:
	mkdir $@
	rm -rf $@/*.txt

$(OBJ):
	mkdir $@

$(BINDIR):
	mkdir $@

test: $(BIN) $(TEST)/bin $(TEST)/inputs $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	$(RM) -r $(BINDIR)/** $(OBJ)/** $(TEST)/bin/** $(TEST)/inputs/*.txt