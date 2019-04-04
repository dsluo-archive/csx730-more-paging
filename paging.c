#include <stdio.h>
#include <stdlib.h>

struct addr_t{
    unsigned long pn0:13;
    unsigned long pn1:13;
    unsigned long pn2:13;
    unsigned long pn3:13;
    unsigned long off:12;

};

typedef struct addr_t addr_t;

union entry_type {
    addr_t frame;
    union entry_type * next;
};

typedef union entry_type entry_type;


int main() {

  setvbuf(stdout, NULL, _IONBF, 0); // disable output buffering
  printf("addr_t size: %lu\n", sizeof(addr_t));

  addr_t addr = { 1, 2, 3, 4, 10 };

  return 0;

} // main
