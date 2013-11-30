#include <stdio.h>
#include <sys/utsname.h>
#include <linux/errno.h>
#include "set_mlimit.h"

#define TOTAL_CALLS 10

int main() {
    int ret;
    
    ret = set_mlimit((uid_t)10021, (long)10000);
    if(ret == 0){
        printf("Succeed, the value: %d\n", ret);
    }else{
        printf("Failed, the value: %d\n", ret);
    }

    return 0;
}
