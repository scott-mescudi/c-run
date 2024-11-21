#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkIfCFile(const char* filename){
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

// gcc -o program Crun.c build.c 
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

// int LinkBuild(char* filename, char* linkerFiles){
//     int ok = checkIfCFile(filename);
//     if (ok != 0){
//         return 1;
//     }

//     for (int i = 0; i < strlen(linkerFiles); i++){
//         printf("%s\n", linkerFiles);
//     }

//     char* baseFile = stripExtension(filename);
    
//     char* command;
//     command = (char*)malloc(strlen(filename)+1 + strlen(baseFile)+1 + strlen("gcc -o"));
//     strcpy(command, "gcc -o ");
//     strcat(command, baseFile);
//     strcat(command, " ");

    
//     strcat(command, filename);
//     strcat(command, " ");
//     //add linker files here

//     printf("%s\n", command);

//     // if (system(command) != 0){
//     //     free(command);
//     //     free(baseFile);
//     //     return 1;
//     // }

//     free(command);
//     free(baseFile);
//     return 0;
// }