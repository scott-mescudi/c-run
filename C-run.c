#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <ctype.h>

#define RESET   "\033[0m"
#define GREEN   "\033[32m"

void build(const char* filename, const char* exeFilename, const char* ext) {
    size_t commandSize = strlen("gcc ") + strlen(filename) + strlen(" -o ") + strlen(exeFilename) + strlen(ext) + 1;
    char* command = (char*)malloc(commandSize);
    
    if (command == NULL) {
        printf("Memory allocation failed!\n");
        return; // Added return to handle allocation failure
    }

    snprintf(command, commandSize, "gcc %s -o %s%s", filename, exeFilename, ext);
    int res = system(command);
    if (res == -1) {
        perror("Error compiling program.");
    }

    free(command);  // Correctly freeing memory
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

void run(const char* exeFilename, const char* ext) {
    size_t commandSize = strlen(exeFilename) + strlen(ext) + 5;
    char* command = (char*)malloc(commandSize);

    if (command == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    #ifdef _WIN32
        snprintf(command, commandSize, "%s%s", exeFilename, ext);
    #else
        snprintf(command, commandSize, "./%s%s", exeFilename, ext);
    #endif

    if (!exists(command)) {
        printf("Executable not found.\n");
        free(command);  // Free memory before returning
        return;
    }

    clock_t start = clock();
    system(command);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("\n---------------------------------");
    printf(GREEN "\nTime taken: %f seconds\n" RESET, time_taken);

    if (remove(command) != 0) {
        printf("Failed to delete executable.\n");
    }

    free(command);  // Free allocated memory
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
        free(exeName);  // Properly freeing memory
    } else {
        printf("Invalid file format. Please provide a C source file.\n");
    }
}

void runPipe(char *argv[]) {
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
        run(exeName, ext);
        free(exeName);  // Properly freeing memory
    } else {
        printf("Invalid file.\n");
    }
}

int main(int argc, char* argv[]) {
    if (argc > 1) {
        if (strcmp(argv[1], "build") == 0 && argc > 2) {
           buildPipe(argv);
        } else if (strcmp(argv[1], "run") == 0 && argc > 2) {
            runPipe(argv);
        } else {
            printf("Invalid selection\n");
        }
    } else {
        printf("Usage: c-run [build||run] filename\n");
    }

    return 0;
}
