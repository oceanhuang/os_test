#include <stdio.h>
#include <sys/syscall.h>

int main(int argc, char **argv){
	FILE *f;
	int i;

	if(argc < 3){
		printf("Incorrect arg number, argc: %d\nUsage: wfile filename text_to_append_line1 text_to_append_line2 ...\n", argc);
		return; 
	}

	f = fopen(argv[1], "at");
	if (f == NULL) {
		fprintf(stderr, "Can't open output file !\n");
  		exit(1);
	}

	for(i=2; i<argc; i++){
		fprintf( f, "%s\n", argv[i]);
	}
	

	fclose(f);
	
	return;

}