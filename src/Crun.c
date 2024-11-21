#include <stdio.h>
#include <string.h>

#include "./header/build.h"

int BuildPipe(int argc, char* argv[]){
    if (strcmp(argv[2], "--link") == 0){
        if (LinkBuild("Crun.c", argc, argv) != 0){
            printf("Error building executable");
        }
    }    
}

int main(int argc, char* argv[]) {
    if (strcmp(argv[1], "build") == 0){
        int res = BuildPipe(argc, argv);
    }

    return 0;
}
