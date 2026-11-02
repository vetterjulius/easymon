#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <stdio.h>
#include "filesize.h"

long get_size(const char* path) {
    DIR* d = opendir(path);
    struct stat buffer;
    if (d == NULL) {
        printf("Error opening folder.\n");
        exit(1);
    }
    long size = 0;
    for (struct dirent* de = readdir(d); de != NULL; de = readdir(d)) {
        int exists = stat(de->d_name, &buffer);
        if (exists < 0) {
            fprintf(stderr, "Couldn't stat %s\n", de->d_name);
            exit(1);
        }
        size += buffer.st_size;

        if (S_ISDIR(buffer.st_mode)) {
            size += buffer.st_size;
        }
    }
    closedir(d);
    return size;
}
