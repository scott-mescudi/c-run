#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./header/build.h"

int BuildPipe(int argc, char* argv[]){
    if (strcmp(argv[2], "--link") == 0){
        if (argc < 4){
            printf("Error: missing linker files");
            return 1;
        }

        char* linkers = GetLinkerFiles(argc, argv);

        if (LinkBuild(argv[3], linkers) != 0){
            printf("Error building linked executable");
            free(linkers);
            return 1;
        }

        free(linkers);
        return 0;
    }else{
        if (strcmp(argv[2], ".") == 0){
           
            char* linkers = GetFilesInDir(".");
            if (LinkBuild("main.c", linkers) != 0){
                printf("Error building linked executable");
                free(linkers);
                return 1;
            }

            free(linkers);
            return 0;
        }

        if (Build(argv[2]) != 0){
            printf("Error building executable");
            return 1;
        }

    }
    return 0;   
}