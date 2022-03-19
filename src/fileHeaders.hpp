void printHelpText(void);

void readFile(char *infile, std::ostream &out);
void readFile(std::string infile, std::ostream &out);
void readFile(char *infile, std::ostream &out, bool count);
void readFile(std::string infile, std::ostream &out, bool count);

std::string numberedLines(std::string text);
