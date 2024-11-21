#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

char* GetFilesInDir(const char *path) {
    struct dirent *entry;
    DIR *dp = opendir(path);

    if (dp == NULL) {
        perror("opendir");
        return NULL;
    }

    char* linkerfiles = calloc(1,1);
    while ((entry = readdir(dp)) != NULL) {
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && strstr(entry->d_name, ".c")) {
            size_t n = strlen(entry->d_name);
            size_t currnet = strlen(linkerfiles);
            size_t total = n + currnet + 2;

            linkerfiles = realloc(linkerfiles, total);
            strcat(linkerfiles, entry->d_name);
            strcat(linkerfiles, " ");
        }
    }

    closedir(dp);
    return linkerfiles;
}

int main() {
    const char *dir_path = "./src";
    char* links = list_files(dir_path);
    printf("%s\n", links);
    return 0;
}

