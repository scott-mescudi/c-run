#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char* GetLinkerFiles(int argc, char* argv[]){
    char* linkers = calloc(1,1);
    for (int i = 0; i < argc; i++){
        if (strstr(argv[i], ".c") != NULL){
            size_t size = strlen(argv[i]);
            size_t linksize = strlen(linkers);
            size_t total = size + linksize + 2;

            linkers = realloc(linkers, total);
            strcat(linkers, argv[i]);
            strcat(linkers, " ");
        }
    }

    return linkers;
}

int main(int argc, char* argv[]){
    char* linkers = GetLinkerFiles(argc, argv);
   
    printf("%s\n", linkers);
    free(linkers);

    return 0;
}
