#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int checkIfCFile(const char* filename){
    if (strlen(filename) > 100){
        printf("Filename is too large");
        return 1;
    }

    if (strstr(filename, ".c") != NULL){
            return 0;
    }

    return 1;
}

char* stripExtension(const char* filename){
    char* baseFilename;
    baseFilename = (char*)malloc(strlen(filename)+1);
    if (baseFilename == NULL){
        return NULL;
    }

    strcpy(baseFilename, filename);

    char* dotpos = strrchr(baseFilename, '.');
    if (dotpos != NULL) {
        *dotpos = '\0';
    }

    return baseFilename;
}

char* GetLinkerFiles(int argc, char* argv[]){
    char* linkers = calloc(1,1);
    for (int i = 0; i < argc; i++){
        if (strstr(argv[i], ".c") != NULL){
            size_t size = strlen(argv[i]);
            size_t linksize = strlen(linkers);
            size_t total = size + linksize + 2;

            linkers = realloc(linkers, total);
            strcat(linkers, argv[i]);
            strcat(linkers, " ");
        }
    }

    return linkers;
}


int Build(char* filename){
    int ok = checkIfCFile(filename);
    if (ok != 0){
        return 1;
    }

    char* baseFile = stripExtension(filename);
    
    char* command;
    command = (char*)malloc(strlen(filename)+1 + strlen(baseFile)+1 + strlen("gcc -o"));
    strcpy(command, "gcc -o ");
    strcat(command, baseFile);
    strcat(command, " ");
    strcat(command, filename);
    strcat(command, " ");

    if (system(command) != 0){
        free(command);
        free(baseFile);
        return 1;
    }

    free(command);
    free(baseFile);
    return 0;
}



int LinkBuild(const char* filename, char* linkerfiles){
    int ok = checkIfCFile(filename);
    if (ok != 0){
        printf("here");// debug
        return 1;
    }

    char* baseFile = stripExtension(filename);
    
    
    char* command;
    command = (char*)malloc(strlen(filename)+1 + strlen(baseFile)+1 + strlen("gcc -o") +  strlen(linkerfiles)+1);
    strcpy(command, "gcc -o ");
    strcat(command, baseFile);
    strcat(command, " ");
    strcat(command, linkerfiles);

    
    if (system(command) != 0){
        free(linkerfiles);
        free(command);
        free(baseFile);
        return 1;
    }
    
    free(command);
    free(baseFile);
    return 0;
}

char* GetFilesInDir(const char *path, char* fileExtension) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return NULL;
    }

    char* linkerfiles = calloc(1,1);
    while ((entry = readdir(dp)) != NULL) {
        if (strstr(entry->d_name, fileExtension) != NULL) {
            size_t n = strlen(entry->d_name);
            size_t currnet = strlen(linkerfiles);
            size_t total = n + currnet + 2;

            linkerfiles = realloc(linkerfiles, total);
            strcat(linkerfiles, entry->d_name);
            strcat(linkerfiles, " ");
        }
    }

    closedir(dp);
    return linkerfiles;
}