#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
	assert(argc >= 3);
	
	int n = atoi(argv[2]);
	assert(n > 0);
	printf("%d\r\n", n);
	int parallel = 0; 
	int status;
	int stop=0;
	int i;
	int id;
	for (i = 3; i < argc && !stop; i++) {
	
			
		if (parallel >= n) {	
			wait(&status);
			if(WIFEXITED(status) == 0) { 
				printf("KILLED\r\n");	
			stop=1;
				}
			parallel--;
		}
			if(!stop)
{
				id = fork();
				if (id == 0) {
					execl(argv[1], argv[1], argv[i], NULL);		
				}
				parallel++;
			} 
				
		
	} 	
	for(i=0;i < parallel;i++)
	{
		wait(NULL);
	}	
    return 0;
}
