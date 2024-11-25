#include <stdio.h>
#include <string.h>

#include "./header/pipe.h"
#include "./header/misc.h"


int main(int argc, char* argv[]) {
    if (argc < 2){
        printUsage();
        return 1;  
    }

    // 2 args
    if (strcmp(argv[1], "gcv") == 0){
        int res = version();
        if (res != 0){
            printf("[-] Failed to get gcc version\n");
            return 1;
        }
        return 0;
    }

    if (strcmp(argv[1], "clean") == 0){
        clean();
        return 0;
    }

    if (strcmp(argv[1], "version") == 0){
        printf("Version 2.0.0");
        return 0;
    }

    if (strcmp(argv[1], "help") == 0){
        printUsage();
        return 0;
    }

    // 3+ args 
    if (argc < 3){
        printUsage();
        return 1;
    }

    if (strcmp(argv[1], "init") == 0){
        init(argv[2]);
        return 0;
    }

    if (strcmp(argv[1], "run") == 0){
        int res = RunPipe(argc, argv);
        if(res != 0){
            return 1;
        }

        return 0;
    }

    if (strcmp(argv[1], "build") == 0){
        int res = BuildPipe(argc, argv);
        if(res != 0){
            printf("[-] Failed to compiled binary\n");
            return 1;
        }

        printf("[+] Compiled binary\n");
        return 0;
    }

    return 0;
}

// TODO add recurisve flag
