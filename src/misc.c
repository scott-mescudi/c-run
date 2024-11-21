#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int version() {
    int res = system("gcc --version");
    if (res != 0){
        return 1;
    }

    return 0;
}