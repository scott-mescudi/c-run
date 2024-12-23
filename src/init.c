#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <sys/stat.h>

#ifdef _WIN32
    #include <direct.h>
    #define MKDIR(dir) _mkdir(dir) 
#else
    #define MKDIR(dir) mkdir(dir, 0755) 
#endif



const char DATA[256] = "#include <stdio.h>\n#include <stdlib.h>\n\nint main(int argc, char* argv[]){\n\tprintf(\"Hello, World!\");\n\n\treturn 0;\n}";

void init(char* projectName){
    if (strlen(projectName) >= 200){
        printf("[-] Project name is too big '%s'", projectName);
        return;
    }

    if (MKDIR(projectName) == 0) { 
        printf("[+] Successfully initialize '%s'.\n", projectName);
    } else {
        printf("[-] Error creating directory '%s'", projectName);
        return;
    }

    const char* subdirs[] = {"header", "src", "bin"} ;
    for (int i = 0; i < sizeof(subdirs) / sizeof(subdirs[0]); i++){
        char subDirPath[256];
        snprintf(subDirPath, sizeof(subDirPath), "%s/%s", projectName, subdirs[i]);

        if (MKDIR(subDirPath) == 0) { 
            printf("[+] Successfully created subdirectory '%s' inside project '%s'.\n", subDirPath, projectName);
        } else {
            printf("[-] Error creating subdirectory '%s'.\n", subDirPath);
            return;
        }
    }

    char filename[256];
    snprintf(filename, sizeof(filename), "%s/%s", projectName, "main.c");
    FILE* fptr;
    fptr = fopen(filename, "w");
    fprintf(fptr, DATA);
    fclose(fptr);
}