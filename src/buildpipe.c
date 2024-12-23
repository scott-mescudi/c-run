#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "./header/build.h"

int BuildPipe(int argc, char* argv[]){
    if (strcmp(argv[2], "--link") == 0){
        if (argc < 4){
            return 1;
        }

        char* linkers = GetLinkerFiles(argc, argv);

        if (LinkBuild(argv[3], linkers) != 0){
            free(linkers);
            return 1;
        }

        free(linkers);
        return 0;
        
    } else if (strcmp(argv[2], "./...") == 0) {
        char* linkers = RecursiveGetFilesInDir(".", ".c");
        if (linkers == NULL) {
            return 1;
        }
        
        if (LinkBuild("main.c", linkers) != 0){
            return 1;
        }
        return 0;
    }else{
        if (strcmp(argv[2], ".") == 0){
            char* linkers = GetFilesInDir(".", ".c");
            if (linkers == NULL) {
                return 1;
            }
            
            if (LinkBuild("main.c", linkers) != 0){
                return 1;
            }
            return 0;
        }

        if (Build(argv[2]) != 0){
            return 1;
        }

    }
    return 0;   
}