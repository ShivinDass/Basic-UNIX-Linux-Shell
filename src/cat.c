#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	if(argc==1)
	{
		printf("(Enter \"exit\" to quite)\n");
		while(1)
		{
			char inp[10000];
			fgets(inp,10000,stdin);
			if(strcmp(inp,"exit\n")==0)
			{
				break;
			}
			printf("%s", inp);
		}
	}
	else if(argv[1][0]=='-')
	{
		if(argc>3 && ((strcmp(argv[1],"-n")==0 && strcmp(argv[2],"-e")==0)||(strcmp(argv[1],"-e")==0 && strcmp(argv[2],"-n")==0)))
		{
			for(int i=3; i<argc; i++)
			{
				int count=1;
				char inp[10000];
				FILE *f;
				f=fopen(argv[i],"r");
				if(f==NULL)
				{
					printf("Error: Couldn't open the file\n");
					return 0;
				}
				else
				{
					while(fgets(inp,10000,f))
					{
						inp[strlen(inp)-1]='$';
						printf("%d %s\n", count++, inp);
					}
				}
			}
		}
		else if(strcmp(argv[1],"-e")==0)
		{
			for(int i=2; i<argc; i++)
			{
				char inp[10000];
				FILE *f;
				f=fopen(argv[i],"r");
				if(f==NULL)
				{
					printf("Error: Couldn't open the file\n");
					return 0;
				}
				else
				{
					while(fgets(inp,10000,f))
					{
						inp[strlen(inp)-1]='$';
						printf("%s\n", inp);
					}
				}
			}
		}
		else if(strcmp(argv[1],"-n")==0)
		{
			int count=1;
			for(int i=2; i<argc; i++)
			{
				char inp[10000];
				FILE *f;
				f=fopen(argv[i],"r");
				if(f==NULL)
				{
					printf("Error: Couldn't open the file\n");
					return 0;
				}
				else
				{
					while(fgets(inp,10000,f))
					{
						printf("%d %s", count++,inp);
					}
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
			char inp[10000];
			FILE *f;
			f=fopen(argv[i],"r");
			if(f==NULL)
			{
				printf("Error: Couldn't open the file\n");
				return 0;
			}
			else
			{
				while(fgets(inp,10000,f))
				{
					printf("%s", inp);
				}
			}
		}
	}
}