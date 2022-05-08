#include "types.h"
#include "stat.h"
#include "user.h"

int main(int arc, char*argv[]) {
    set_prior(30);
    int i, k;
    printf (1, "proc3 \n");
    for(i=0; i < 43000; i++) {
        asm("nop");
        for(k = 0; k < 43000; k++) {
            asm("nop");
        }
    }
    printf (1, "exiting proc3 \n");
    exit(0);
}