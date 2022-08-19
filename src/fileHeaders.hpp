void getHelp(void);
void getHelp(std::string cmd);

void readFile(char *infile, std::ostream &out);
void readFile(std::string infile, std::ostream &out);
void readFile(char *infile, std::ostream &out, bool count);
void readFile(std::string infile, std::ostream &out, bool count);

void writeFile(char *infile, char *outfile);
void writeFile(std::string infile, std::string outfile);

std::string numberedLines(std::string text);
