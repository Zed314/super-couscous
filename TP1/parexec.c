#include <stdio.h>
#include <assert.h>
#include <unistd.h>
 #include <sys/wait.h>
#include <stdlib.h>
int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
	assert(argc>=4);
	int nbPMax;
	assert(nbPMax=strtol(argv[2],(char **)NULL,10)>0);
	int i;
	
	int nbP=0;
	
	for(i=3;i<argc;i++)
	{
		if(nbP>nbPMax)
		{
			wait(NULL);
			nbP--;
		}
		
		if(fork()==0)
		{
			execl(argv[1],argv[1],argv[i],NULL);
		}
		else
		{
				nbP++;
				
		}
	}
	for(i=0;i<nbP;i++)
	{
		wait(NULL);
	}

    return 0;
}
