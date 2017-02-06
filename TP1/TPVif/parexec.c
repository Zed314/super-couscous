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
	int tab[50];
	for(i=0;i<50;i++)
	{
		tab[i]=-1;
	}
	for (i = 3; i < argc && !stop; i++) {
	
			
		if (parallel >= n) {	
			int temp=wait(&status);
			int j=0;
			for(;j<50;j++)
			{
				if(tab[j]==temp)
				{
					tab[j]=-1;
					break;
				}
			}
			if(WIFEXITED(status) == 0) { 
				printf("HEADSHOT 360 SCOPELESS roxxxooorr\r\n");	
				stop=1;
				/*kill(0, SIGTERM);
				printf("zob\r\n");*/
				for(j=0;j<50;j++)
				{
					if(tab[j]!=-1)
					{
					kill(tab[j],SIGTERM);
					
					}
				}
				parallel = 0;
			}
			parallel--;
		}
			if(!stop)
{
				id = fork();
				if (id == 0) {
					execl(argv[1], argv[1], argv[i], NULL);		
				}
				tab[i-3]=id;
				parallel++;
			} 
				
		
	} 	
	for(i=0;i < parallel;i++)
	{
		wait(NULL);
	}	
printf("ee");
    return 0;
}
