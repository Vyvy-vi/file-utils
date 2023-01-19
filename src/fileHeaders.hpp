void getHelp(void);
void getHelp(std::string cmd);

void readFile(char *infile, std::ostream &out);
void readFile(std::string infile, std::ostream &out);
void readFile(char *infile, std::ostream &out, bool count);
void readFile(std::string infile, std::ostream &out, bool count);

void copyFile(char *infile, char *outfile);
void copyFile(std::string infile, std::string outfile);

void writeFile(char *outfile, char *content);
void writeFile(std::string outfile, std::string content);

std::string numberedLines(std::string text);
