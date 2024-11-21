#include <stdio.h>
#include <string.h>

#include "./header/pipe.h"



int main(int argc, char* argv[]) {
    if (argc < 3){
        printf("C [build|run] <filename>");
        return 1;
    }

    if (strcmp(argv[1], "build") == 0){
        int res = BuildPipe(argc, argv);
        if(res != 0){
            return 1;
        }
    }

    return 0;
}
