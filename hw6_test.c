#include <stdio.h>
#include <sys/syscall.h>

int ext4_cowcopy(const char __user *src, const char __user *dest){
	syscall(378, src, dest);

}

int main(int argc, char **argv) {
	FILE *f;

	printf("=== beginning of test for system call: ext4_cowcopy ===\n");
	printf("*** Testcases calling ext4_cowcopy will fail ***\n");
	printf("1. nonexist src file\n");
	ext4_cowcopy("/data/local/tmp/nonexist", "/data/local/tmp/cow_of_nonexist");

	printf("2 src file is a directory.\n");
	ext4_cowcopy("/data/local/tmp/dir/", "/data/local/tmp/cow_of_dir");

	printf("3 dest file is a directory.\n");
	ext4_cowcopy("/data/local/tmp/hw5", "/data/local/tmp/cow_of_hw5/");

	printf("4 src file is not in ext4 filesystem.\n");
	ext4_cowcopy("/proc/last_kmsg", "/data/local/tmp/cow_of_last_kmsg");

	printf("5 dest file is not in the same mount point as src file.\n");
	ext4_cowcopy("/data/local/tmp/hw5", "/system/bin/yoyo");

	printf("*** Testcases calling ext4_cowcopy will success ***\n");
	ext4_cowcopy("/data/local/tmp/hw5", "/data/local/tmp/cow_of_hw5");

	printf("=== end of test for system call: ext4_cowcopy ===\n");
	f = fopen("/data/local/tmp/cow_of_hw5", "a");
	if (f == NULL) {
		fprintf(stderr, "Can't open output file !\n");
  		exit(1);
	}
	fclose(f);
	return 0;
}

