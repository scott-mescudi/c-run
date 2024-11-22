#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "./header/run.h"


int RunPipe(int argc, char* argv[]){
    char * filename = argv[2];
    int isLinker = 1;

    if (strcmp(filename, ".") == 0){
        isLinker = 0;
    }

    if (argc == 3){
        int res;
        if(isLinker == 1){
            res = run(filename, " ");
        }else{
            res = Linkrun(" ");    
        }

        if (res != 0){
            return 1;
        }
        
        return 0;
    }

    if (argc > 3){
        char* args = getargs(argc, argv);

        int res;
        if(isLinker == 1){
            res = run(filename, args);
        }else{
            res = Linkrun(args);    
        }
        
        if (res != 0){
            free(args);
            return 1;
        }

        free(args);
        return 0;
    }
}