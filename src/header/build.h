int Build(char* filename);
int LinkBuild(const char* filename, char* linkerfiles);
char* GetFilesInDir(const char *path);
char* GetLinkerFiles(int argc, char* argv[]);