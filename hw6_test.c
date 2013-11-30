#include <stdio.h>
#include <errno.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <pwd.h>
#include <signal.h>

void test1() {
		printf("parent uid: %d\n", getuid());
		printf("parent pid: %d\n", getpid());
}

int main(int argc, char **argv) {
	
	int limit = 100000000; // 100 mb limit
	syscall(378, 10070, limit);
	test1();
	int i, mem;
	int memory[] = {80000000, 50000000};

	pid_t p = fork(); 

	if (0 == p) {
		printf("### Child 1, pid: %d uid: %d\n", getpid(), getuid());
		// this is children
		mem = memory[0];
		char *m = (char*)malloc(mem);
		int l = 0;
		for (l = 0; l < mem; ++l) {
				m[l] = '\0';
		}
		sleep(10);
		printf("### Child 1 should have been killed...\n");
		return 0;
	}
	else {
		// this is parent, fork again
		p = fork();
		if (0 == p){
			// this is second child
			printf("### Child 2, pid: %d uid: %d\n", getpid(), getuid());
			sleep(5);
			mem = memory[1];
			char *m = (char*)malloc(mem);
			int l = 0;
			for (l = 0; l < mem; ++l) {
					m[l] = '\0';
			}
			printf("### Child 2 finished malloc \n", getpid(), getuid());
			sleep(5);
			return 0;
		}
		else {
			sleep(15);
			return 0;
		}			
	}

	return 0;
}

