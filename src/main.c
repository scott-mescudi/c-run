#include <stdio.h>
#include <string.h>

#include "./header/pipe.h"
#include "./header/misc.h"

int main(int argc, char* argv[]) {
    if (argc < 2){
        printf("C [build|run] <filename>");
        return 1;  
    }

    //get gcc version
    if (strcmp(argv[1], "gcv") == 0){
        int res = version();
        if (res != 0){
            printf("[-] Failed to get gcc version");
            return 1;
        }
        return 0;
    }

    if (strcmp(argv[1], "clean") == 0){
        clean();
        return 0;
    }

    //main build and run logic
    if (argc < 3){
        printf("C [build|run] <filename>");
        return 1;
    }

    if (strcmp(argv[1], "build") == 0){
        int res = BuildPipe(argc, argv);
        if(res != 0){
            printf("[-] Failed to compiled binary");
            return 1;
        }

        printf("[+] Compiled binary");
    }

    return 0;
}
