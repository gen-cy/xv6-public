#include "types.h"
#include "user.h"

void work() {
    int i,k;
    for(i = 0; i < 43000; i++) {
        for(k = 0; k < 43000; k++) {
            asm("nop");
        }
    }
}

int main() {
    set_prior(0);
    int i = 0;
    int pid = 0;
    for(i = 0; i < 3; i++) {
        pid = fork();
        if(!pid) {
            set_prior(i * 10);
            work(0);
            printf(0, "child %d done PRIORITY %d\n", getpid(), i*10);
            exit(0);
        }
    }
    if(pid) {
        for(i = 0; i < 3; i++) //43000*3
            wait(0);
    }
    printf(0, "parent %d done\n", getpid());
    exit(0);
}