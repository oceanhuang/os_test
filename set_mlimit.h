#ifndef __SET_MLIMIT_H_
#define __SET_MLIMIT_H_

#include <sys/syscall.h>
#include <linux/types.h>

#define __NR_set_mlimit 378

inline long set_mlimit(uid_t uid, long max_mem) {
    return syscall(__NR_set_mlimit, uid, max_mem);
}

#endif  // __SET_MLIMIT_H_
