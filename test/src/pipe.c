#include <stdio.h>
#include <string.h>
#include "./header/build.h"

int BuildPipe(int argc, char* argv[]){
    if (strcmp(argv[2], "--link") == 0){
        if (argc < 4){
            printf("Error: missing linker files");
            return 1;
        }

        if (LinkBuild(argv[3], argc, argv) != 0){
            printf("Error building linked executable");
            return 1;
        }
    }else{
        if (Build(argv[2]) != 0){
            printf("Error building executable");
            return 1;
        }

    }
    
    return 0;   
}