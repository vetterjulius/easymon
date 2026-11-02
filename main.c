#include "filesize.h"
#include <stdio.h>

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: esm <path>\n");
        return 1;
    }
    long result = get_size(argv[1]);
    printf("Size: %d\n", result);
}

