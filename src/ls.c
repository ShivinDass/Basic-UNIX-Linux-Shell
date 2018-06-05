#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dirent.h>
#include <inttypes.h>

int main(int argc, char const **argv)
{
	struct dirent **filenames;
	int n;
	int flag=0;

	if(argc==1)
	{
		n=scandir(".",&filenames,NULL,alphasort);
	}
	else if(argv[1][0]=='-')
	{
		flag=1;
		if(argc>=3 && ((strcmp(argv[1],"-a")==0 && strcmp(argv[2],"-i")==0)||(strcmp(argv[1],"-i")==0 && strcmp(argv[2],"-a")==0)))
		{
			if(argc==3)
			{
				n=scandir(".",&filenames,NULL,alphasort);
			}
			else
			{
				n=scandir(argv[3],&filenames,NULL,alphasort);
			}
		}
		else if(argc==3)
		{
			n=scandir(argv[2],&filenames,NULL,alphasort);
		}
		else
		{
			n=scandir(".",&filenames,NULL,alphasort);
		}
	}
	else
	{
		n=scandir(argv[1],&filenames,NULL,alphasort);
	}



	/*if(n<0)
	{
		perror("scandir");
	}
	else
	{*/
	if(flag==1)
	{
		if(argc>=3 && ((strcmp(argv[1],"-a")==0 && strcmp(argv[2],"-i")==0)||(strcmp(argv[1],"-i")==0 && strcmp(argv[2],"-a")==0)))
		{
			if(n<0)
			{	
				perror("scandir");
				return 0;
			}
			while(n--)
			{
				printf("%ju %s    ",(uintmax_t)filenames[n]->d_ino,filenames[n]->d_name);
				free(filenames[n]);
			}
			printf("\n");
			free(filenames);
		}
		else if(strcmp(argv[1],"-a")==0)
		{
			if(n<0)
			{	
				perror("scandir");
				return 0;
			}
			while(n--)
			{
				printf("%s  ",filenames[n]->d_name);
				free(filenames[n]);
			}
			printf("\n");
			free(filenames);
		}
		else if(strcmp(argv[1],"-i")==0)
		{
			if(n<0)
			{
				perror("scandir");
				return 0;
			}
			while(n--)
			{
				if((filenames[n]->d_name)[0]!='.')
				{
					printf("%ju %s    ",(uintmax_t)filenames[n]->d_ino,filenames[n]->d_name);
					free(filenames[n]);
				}
			}
			printf("\n");
			free(filenames);
		}
		else
		{
			printf("Error: Invalid selected option\n");
		}
	}
	else
	{
		if(n<0)
		{
			perror("scandir");
			return 0;
		}
		while(n--)
		{
			if((filenames[n]->d_name)[0]!='.')
			{
				printf("%s  ",filenames[n]->d_name);
				free(filenames[n]);
			}
		}
		printf("\n");
		free(filenames);
	}
	return 0;
}