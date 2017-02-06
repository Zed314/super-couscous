#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
	assert(argc == 2);
	int n = atoi(argv[1]);
	assert(n > 0);

	int i;
	printf("%d: debut\r\n", getpid());
	for (i = n; i > 0; i--) {
		printf("%d: %d\r\n", getpid(), i);
		sleep(1);
	}
	printf("%d: fin\r\n", getpid()); 
	 	

    return 0;
}
