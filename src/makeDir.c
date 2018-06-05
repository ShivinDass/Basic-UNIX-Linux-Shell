#include <sys/types.h>
#include <sys/stat.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc==1 || (argc==2 && argv[1][0]=='-'))
	{
		printf("Error: Not enough arguments\n");
	}
	else if(argv[1][0]=='-')
	{
		if(argc>4 && strcmp(argv[1],"-m")==0 && strcmp(argv[3],"-v")==0)
		{
			for(int i=4; i<argc; i++)
			{
				mode_t mode=strtol(argv[2],NULL,8);
				int status=mkdir(argv[i],mode);
				if(status==-1)
				{
					printf("Error:File %s could not be created\n",argv[i]);
				}
				else
				{
					printf("File %s was created\n", argv[i]);
				}
			}
		}
		else if(argc>4 && strcmp(argv[1],"-v")==0 && strcmp(argv[2],"-m")==0)
		{
			for(int i=4; i<argc; i++)
			{
				mode_t mode=strtol(argv[3],NULL,8);
				int status=mkdir(argv[i],mode);
				if(status==-1)
				{
					printf("Error:File %s could not be created\n",argv[i]);
				}
				else
				{
					printf("File %s was created\n", argv[i]);
				}
			}
		}
		else if(strcmp(argv[1],"-v")==0)
		{
			for(int i=2; i<argc; i++)
			{
				int status=mkdir(argv[i],0777);
				if(status==-1)
				{
					printf("Error:File %s could not be created\n",argv[i]);
				}
				else
				{
					printf("File %s was created\n", argv[i]);
				}
			}
		}
		else if(strcmp(argv[1],"-m")==0 && argc>3)
		{
			for(int i=3; i<argc; i++)
			{
				mode_t mode=strtol(argv[2],NULL,8);
				int status=mkdir(argv[i],mode);
				if(status==-1)
				{
					printf("Error:File %s could not be created\n",argv[i]);
				}
			}
		}
		else
		{
			printf("Error: Invalid input format\n");
		}

	}
	else
	{
		for(int i=1; i<argc; i++)
		{
			int status=mkdir(argv[i],0777);
			if(status==-1)
			{
					printf("Error:File %s could not be created\n",argv[i]);
			}
		}
	}
	return 0;
}