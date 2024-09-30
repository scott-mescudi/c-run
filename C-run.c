#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#ifdef WIN32
#include <io.h>
#define F_OK 0
#define access _access
#else
#include <unistd.h>
#endif

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

void build(const char* filename, const char* exeFilename, const char* ext) {
    size_t commandSize = strlen("gcc ") + strlen(filename) + strlen(" -o ") + strlen(exeFilename) + strlen(ext) + 1;
    char* command = (char*)malloc(commandSize);
    
    if (command == NULL) {
        printf("Memory allocation failed!\n");
        free(command);
    }

    snprintf(command, commandSize, "gcc %s -o %s%s", filename, exeFilename, ext);
    int res = system(command);
    if (res == -1) {
        perror("Error compiling program.");
    }
    if (command != NULL) {
        free(command);
        return;
    }

    return;
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



int exists(const char *fname) {
    if (access(fname, F_OK) == 0) {
        return 1;
    } else {
        return 0; 
    }
}

void run(const char* exeFilename, const char* ext){
    size_t commandSize = strlen(exeFilename) + strlen(ext) + 1;
    char* command = (char*)malloc(commandSize);

    if (command == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    int i = exists(exeFilename);
    if (i == 1) {
        printf("Executable not found.\n");
        return;
    }

    snprintf(command, commandSize, "%s%s", exeFilename, ext);
    clock_t start = clock();
    system(command);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n---------------------------------");
    printf(GREEN "\nTime taken: %f seconds\n" RESET, time_taken);


    if (remove(command) != 0) {
        printf("Failed to delete executable.\n");
    }

    if (command != NULL) {
        free(command);
    }


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

int main(int argc, char* argv[]) {
    if (argc > 1){
        if (strcmp(argv[1], "build") == 0){
            if (argc > 2){
                char *result = strstr(argv[2], ".c");
                
                if (result) {
                    char* exeName = getExeName(argv[2]);
                    char* ext = ".exe";
                    build(argv[2], exeName, ext);
                    if (exeName != NULL){
                        free(exeName);
                    }
                }else{
                    printf("Invalid file format. Please provide a C source file.\n");
                }
            }

        }else if (strcmp(argv[1], "run") == 0){
            if (argc > 2){
                bool result = is_valid_filename(argv[2]);
                if (result) {
                    char* exeName = getExeName(argv[2]);
                    char* ext = ".exe";
                    build(argv[2], exeName, ext);
                    run(exeName, ext);
                    if (exeName != NULL){
                        free(exeName);
                    }
                }else{
                    printf("Invalid file format. Please provide a C source file.\n");
                }
            }
        }else{
            printf("Invalid selection");
        }
    }

    return 0;
}