#include <stdio.h>
#include <sys/syscall.h>

int ext4_cowcopy(const char __user *src, const char __user *dest){
	syscall(378, src, dest);

}


int main(int argc, char **argv){
	int i;
	int res;

	if(argc != 3){
		printf("Incorrect arg number, argc: %d\nUsage: ext4_cowcopy src dest\n", argc);
		return; 
	}

	res = ext4_cowcopy(argv[1], argv[2]);
	if(res == 0)
		printf("ext4_cowcopy done. src: %s , dest: %s\n", argv[1], argv[2]);	
	else
		printf("error happend while ext4_cowcopy. src: %s , dest: %s\n", argv[1], argv[2]);

}