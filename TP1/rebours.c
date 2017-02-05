#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <assert.h>
int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
    if(argc<2)
    {
    	printf("Erreur, il manque un argument!\r\n");
    //	return EXIT_FAILURE;
    		return -1;
    }
    int temps=strtol(argv[1],(char **)NULL,10);
 	assert(temps>0);
 	int i;
 	   printf("%d: debut\r\n",getpid());

  	for(i=temps;i>0;i--)
  	{
  		
		printf("%d: %d\r\n",getpid(),i);
		sleep (1);
  	}
   
    printf("%d: end\r\n",getpid());

    return 0;
}
