int Build(char* filename);
int LinkBuild(const char* filename, char* linkerfiles);
char* GetFilesInDir(const char *path, char* fileExtension);
char* RecursiveGetFilesInDir(const char *path, char* fileExtension);
char* GetLinkerFiles(int argc, char* argv[]);
char* stripExtension(const char* filename);