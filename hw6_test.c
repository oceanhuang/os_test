#include <stdio.h>
#include <sys/syscall.h>


int main(int argc, char **argv) {

	syscall(378, "/data/local/tmp/hw5", "/data/local/tmp/test");

	return 0;
}

