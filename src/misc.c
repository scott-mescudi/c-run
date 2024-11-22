#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

#include "./header/build.h"

int version() {
    int res = system("gcc --version");
    if (res != 0){
        return 1;
    }

    return 0;
}

void clean(){
    struct dirent *entry;
    DIR *dp = opendir(".");

    if (dp == NULL) {
        perror("opendir");
    }

    
    while ((entry = readdir(dp)) != NULL) {
        if (strstr(entry->d_name, ".exe") != NULL || strstr(entry->d_name, ".out") != NULL) {
            if (remove(entry->d_name) == 0) {
                printf("[+] File '%s' deleted successfully.\n", entry->d_name);
            } else {
                perror("[-] Error deleting the file");
            }
        }
    }
}