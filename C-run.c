#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>


void build(const char* filename, const char* exeFilename, const char* ext) {
    size_t commandSize = strlen("gcc ") + strlen(filename) + strlen(" -o ") + strlen(exeFilename) + strlen(ext) + 1;
    char* command = (char*)malloc(commandSize);
    
    if (command == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    snprintf(command, commandSize, "gcc %s -o %s%s", filename, exeFilename, ext);
    int res = system(command);
    if (res == -1) {
        perror("Error compiling program.");
    }

    free(command);  
}

char* getExeName(const char* filename) {
    size_t fsize = strlen(filename);
    char* fname = (char*)malloc(fsize + 1);
    if (fname == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return NULL; 
    }
    
    strcpy(fname, filename); 

    char* dot = strrchr(fname, '.');
    if (dot != NULL && strcmp(dot, ".c") == 0) {
        *dot = '\0';
    }

    return fname;
}

bool exists(const char* fname) {
    FILE *file = fopen(fname, "r");
    
    if (file) {
        fclose(file);
        return true;
    }
    return false;
}

void run(char* args, char* exeFilename, char* ext) {
    size_t exenamesize = strlen(exeFilename) + strlen(ext) + 5;
    char *exename = (char*)malloc(exenamesize);
    if (exename == NULL) {
        printf("Memory allocation failed for exename!\n");
        return;
    }
    snprintf(exename, exenamesize, "%s%s", exeFilename, ext);

    size_t commandSize;
    if (args != NULL){
        commandSize = strlen(exename) +  strlen(args) + 5;
    }else{
        commandSize = strlen(exename) + 5;
    }
    
    char* command = (char*)malloc(commandSize);
    if (command == NULL) {
        printf("Memory allocation failed!\n");
        free(exename);
        return;
    }
    
    
    if (args != NULL){
        #ifdef _WIN32
            snprintf(command, commandSize, "%s %s", exename, args);
        #else
            snprintf(command, commandSize, "./%s %s", exename, args);
        #endif
    }else{
        #ifdef _WIN32
            snprintf(command, commandSize, "%s", exename);
        #else
            snprintf(command, commandSize, "./%s", exename);
        #endif
    }
    
    
    if (!exists(exename)) {
        printf("Executable not found.\n");
        free(command);
        free(exename);
        return;
    }

 
    system(command);
    if (remove(exename) != 0) {
        printf("Failed to delete executable.\n");
    }

    free(command);
    free(exename);
}





bool is_valid_filename(const char* filename) {
    const char* dot = strrchr(filename, '.');
    if (dot == NULL || strcmp(dot, ".c") != 0) {
        return false;
    }

    for (const char* p = filename; *p; p++) {
        if (!isalnum(*p) && *p != '_' && *p != '.') {
            return false;  
        }
    }

    return true;
}

void buildPipe(char *argv[]) {
    #ifdef _WIN32
        char* ext = ".exe";
    #else
        char* ext = "";
    #endif

    if (argv[2] == NULL) {
        printf("No file provided.\n");
        return; // Prevents crashes
    }

    bool fe = exists(argv[2]);
    bool result = is_valid_filename(argv[2]);
    if (result && fe) {
        char* exeName = getExeName(argv[2]);
        if (exeName == NULL) {
            printf("Failed to get exe name.\n");
            return;
        }
        build(argv[2], exeName, ext);
        free(exeName);
    } else {
        printf("Invalid file format. Please provide a C source file.\n");
    }
}

void runPipe(int argc, char *argv[]) {
    #ifdef _WIN32
        char* ext = ".exe";
    #else
        char* ext = "";
    #endif

    if (argv[2] == NULL) {
        printf("No file provided.\n");
        return; // Prevents crashes
    }

    bool fe = exists(argv[2]);
    bool result = is_valid_filename(argv[2]);
    if (result && fe) {
        char *args = NULL;
        if (argc > 3) {  
            int size = 0;
            int capacity = 3;

            args = (char *)malloc(capacity * sizeof(char));
            if (args == NULL) {
                printf("Memory allocation failed!\n");
                return;
            }

            for (int i = 3; i < argc; i++) {
                int arg_len = strlen(argv[i]);

                if (size + arg_len + 1 >= capacity) {
                    capacity = (size + arg_len) * 2;
                    char *temp = realloc(args, capacity * sizeof(char));
                    if (temp == NULL) {
                        printf("Memory reallocation failed!\n");
                        free(args);
                        return;
                    }
                    args = temp;
                }

                if (i > 3) {
                    args[size] = ' ';
                    size += 1;
                }

                strcpy(args + size, argv[i]);
                size += arg_len;
            }

            args[size] = '\0';
        }

        char* exeName = getExeName(argv[2]);
        if (exeName == NULL) {
            printf("Failed to get exe name.\n");
            return;
        }

        build(argv[2], exeName, ext);
        run(args, exeName, ext);  
        free(exeName);
        if (args) free(args);  
    } else {
        printf("Invalid file.\n");
    }
}


int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "build") == 0 && argc > 2) {
           buildPipe(argv);
        } else if (strcmp(argv[1], "run") == 0 && argc > 2) {
            runPipe(argc, argv);
        } else {
            printf("Invalid selection\n");
        }
    } else {
        printf("Usage: c-run [build||run] filename\n");
    }

    return 0;
}