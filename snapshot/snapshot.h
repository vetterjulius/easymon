#define SNAPSHOT_DIR "/var/easymon/snapshots"
#define INITIAL_OFFSET 0

#include "sys/time.h"

typedef struct snp_val
{
    char* name;
    long size;
    struct snp_val* childs;
    int num_childs;
};

typedef struct snapshot
{
    char* timestamp;
    struct snp_val values;
};

int print_snapshot(struct snapshot snp);
