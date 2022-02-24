
CC = g++
CFLAGS = -g -Wall -std=c++14
SRC = src
OBJ = obj
SRCS = $(wildcard $(SRC)/*.cpp)
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
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ)/%.o: $(SRC)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST)/bin/%: $(TEST)/%.cpp
	$(CC) $(CFLAGS) $< -o $@ -lcriterion

$(TEST)/bin:
	mkdir $@

$(OBJ):
	mkdir $@

$(BINDIR):
	mkdir $@

test: $(BIN) $(TEST)/bin $(TESTBINS)
	for test in $(TESTBINS) ; do ./$$test ; done

clean:
	$(RM) -r $(BINDIR)/** $(OBJ)/** $(TEST)/bin/**