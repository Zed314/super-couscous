#include <stdio.h>
#include <assert.h>
#include <unistd.h>
 #include <sys/wait.h>
int main(int argc, char** argv)
{
    printf("Bonjour je suis '%s'\n",argv[0]);
	assert(argc>=3);
	int i;
	int pidFils;
	for(i=2;i<argc;i++)
	{
		pidFils=fork();
		if(pidFils==0)
		{
			execl(argv[1],argv[1],argv[i],NULL);
		}
		else
		{
				
		}
	}
	for(i=0;i<argc-2;i++)
	{
		wait(NULL);
	}

    return 0;
}
