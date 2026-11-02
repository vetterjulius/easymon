#include <stdio.h>
#include "snapshot.h"


int print_snapshot(struct snapshot snp)
{
    struct snp_val root = snp.values;
    printf("Timestamp: %s\nRoot: %s", snp.timestamp, root.name);
    print_contents(root, INITIAL_OFFSET);
}

int print_contents(struct snp_val val, int offset)
{
    print_offset(offset);
    printf("%s: %d\n", val.name, val.size);
    if  (val.childs == NULL) {
        return 0;
    }
    for (int i = 0; i < val.num_childs; i++) {
        print_contents(val.childs[i], offset + 1);
    }
    return 0;
}

int print_offset(int offset) {
    if (offset < 0) {
        return 1;
    }
    char* off_str = " ";
    for (int i = 0; i < offset; i++) {
        printf(off_str);
    }
    return 0;
}