#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct addr_t {
    unsigned long pn0:13;
    unsigned long pn1:13;
    unsigned long pn2:13;
    unsigned long pn3:13;
    unsigned long off:12;
};

typedef struct addr_t addr_t;

union entry_t {
    addr_t frame;
    union entry_t * next;
};

typedef union entry_t entry_t;

#define COUNT (1ul << 13)

entry_t table0[COUNT];

addr_t virt_to_phys(addr_t virt) {
    entry_t entry = table0[virt.pn0];

    if (entry.next == null) {
        entry.next = malloc(sizeof(entry_t) * COUNT);
        memset(entry.next, 0, sizeof(table0));
    }

}

int main() {

    setvbuf(stdout, NULL, _IONBF, 0); // disable output buffering
    printf("addr_t size: %lu\n", sizeof(addr_t));

    addr_t addr = { 1, 3, 7, 15, 31 };

    memset(&table0, 0, sizeof(table0));

    return 0;

} // main
