#include <stdio.h>
#include <sys/syscall.h>


int main(int argc, char **argv) {

	syscall(378, "/data/local/tmp/hw5", "/data/local/tmp/hw8");
	syscall(378, "/system/bin/sh", "/proc/last_kmsg");
	syscall(378, "/data/local/tmp/hw5", "/system/bin/yoyo");

	return 0;
}

