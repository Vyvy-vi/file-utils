void getHelp(void);
void getHelp(const std::string &cmd);

void readFile(const std::string &infile, std::ostream &out);
void readFile(const std::string &infile, std::ostream &out, bool count);

void copyFile(const std::string &infile, const std::string &outfile);

void writeFile(const std::string &outfile, const std::string &content);

std::string numberedLines(std::string text);
