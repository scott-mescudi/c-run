#include <stdio.h>

#include "./header/build.h"

int main(int argc, char* argv[]) {
    if (build("./test/test2.c") != 0){
        printf("Error building executable");
    }
    return 0;
}
