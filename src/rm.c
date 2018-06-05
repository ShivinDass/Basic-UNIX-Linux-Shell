#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char const *argv[])
{	
	if(argc==1 || (argv[1][0]=='-' && argc==2))
	{
		printf("Error: Insufficient Arguments\n");
	}
	else if(argv[1][0]=='-')
	{
		if(argc>3 && ((strcmp(argv[1],"-i")==0 && strcmp(argv[2],"-d")==0)||(strcmp(argv[1],"-d")==0 && strcmp(argv[2],"-i")==0)))
		{
			for(int i=3; i<argc; i++)
			{
				printf("Do you want to delete the file(s)?:");
				char c;
				scanf("%c",&c);
				if(c!='y')
					continue;
				if(remove(argv[i])==-1)
				{
					printf("Error:Couldn't delete the file %s\n",argv[1]);
				}
			}
		}
		else if(strcmp(argv[1],"-i")==0)
		{
			for(int i=2; i<argc; i++)
			{
				struct stat path;
				stat(argv[i], &path);
				if(!S_ISREG(path.st_mode))
				{
					printf("Error: File Couldn't be deleted by rm\n");
					continue;
				}
				printf("Do you want to delete the file?:");
				char c;
				scanf("%c",&c);
				if(c!='y')
					continue;
				if(remove(argv[i])==-1)
				{
					printf("Error:Couldn't delete the file\n");
				}
			}
		}
		else if(strcmp(argv[1],"-d")==0)
		{
			for(int i=2; i<argc; i++)
			{
				if(remove(argv[i])==-1)
				{
					printf("Error:Couldn't delete the file\n");
				}
			}
		}
		else
		{
			printf("Error: Invalid selected option\n");
		}
	}
	else
	{
		for(int i=1; i<argc; i++)
		{
			struct stat path;
			stat(argv[i], &path);
			if(!S_ISREG(path.st_mode))
			{
				printf("Error: File Couldn't be deleted by rm\n");
				continue;
			}
			if(remove(argv[i])==-1)
			{
				printf("Error:Couldn't delete the file\n");
			}
		}
	}
	return 0;
}