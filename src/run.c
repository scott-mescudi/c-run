#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "./header/build.h"



#ifdef _WIN32
    char* ext = ".exe";
    char* pre = "";
#else
    char* ext = "";
    char* pre = "./";
#endif


char* getargs(int argc, char* argv[]){
    char* container = calloc(1, 1);
    for(int i = 3; i < argc; i++){
        size_t argsize = strlen(argv[i]);
        size_t cursize = strlen(container);
        size_t total = argsize + cursize + 2;

        container = realloc(container, total);
        strcat(container, argv[i]);
        strcat(container, " ");
    } 

    return container;
}


int run(char* filename, char* args){
    if (Build(filename) != 0){
        printf("[-] Failed to compile binary");
        return 0;
    }

    char* basefile = stripExtension(filename);
    


    size_t total = strlen(args)+9;
    char* command = (char*)malloc(total);
    snprintf(command, total, "%s%s%s %s", pre, basefile, ext ,args);
    

    char cont[200] = "";
    strcat(cont, basefile);
    strcat(cont, ext);
    strcat(cont, "\0");
    printf("%s\n", cont);// debug

    if (system(command) != 0){
        remove(cont);
        free(command);
        return 1;
    }


    remove(cont);
    free(command);
    free(basefile);
}



int Linkrun(char* args){
    char* basefile = "main";
    char* linker = GetFilesInDir(".", ".c");

    if (LinkBuild("main.c", linker) != 0){
        printf("[-] Failed to compile linked binary");
        free(linker);
        return 0;
    }



    size_t total = strlen(args)+9;
    char* command = (char*)malloc(total);
    snprintf(command, total, "%s%s%s %s", pre, basefile, ext ,args);
    

    char cont[20] = "";
    strcat(cont, basefile);
    strcat(cont, ext);


    if (system(command) != 0){
        remove(cont);
        free(command);
        free(linker);
        return 1;
    }


    remove(cont);
    free(command);
    free(linker);
}
