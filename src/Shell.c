#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <pthread.h>


void cd(char **arguments)
{
	if(arguments[1]==NULL)
	{
		return;
	}
	else
	{
		if(chdir(arguments[1])==-1)
		{
			printf("Error:The directly couldn't be changed\n");
		}
	}
}


void pwd(int c)
{
	char *b=(char *)malloc(1000*sizeof(char));
	getcwd(b,1000);
	if(c==0)
	{
		printf("%s>>", b);
	}
	else
	{
		printf("%s\n", b);
	}
}



void echo(char *inp,char **arguments,int arc)
{
	//printf("%s\n", inp);
	int k=1;
	int fl=0;
	if(arc==1)
	{
		printf("\n");
		return;
	}
	else if(arguments[1][0]=='-')
	{
		if(arc>3 && ((strcmp(arguments[1],"-n")==0 && strcmp(arguments[2],"-E")==0)||(strcmp(arguments[1],"-E")==0 && strcmp(arguments[2],"-n")==0)))
		{
			fl=2;
			k=3;
		}
		else if(strcmp(arguments[1],"-n")==0)
		{
			inp[strlen(inp)-1]=' ';
			k=2;
			fl=1;
		}
		else if(strcmp(arguments[1],"-E")==0)
		{
			k=2;
		}

	}
	

	if(arguments[k][0]=='"' && inp[strlen(inp)-2]=='"')
	{
		if(fl==2)
		{
			inp=inp+12;
		}
		else if(k==2)
		{
			inp=inp+9;
		}
		else
		{
			inp=inp+6;
		}


		if(fl==0)
		{
			inp[strlen(inp)-2]='\n';
			inp[strlen(inp)-1]='\0';
		}
		else
		{
			inp[strlen(inp)-2]='\0';
		}
		printf("%s", inp);
	}
	else
	{
		for(int i=k; i<arc; i++)
		{
			printf("%s", arguments[i]);
			if(i!=arc-1)
			{
				printf(" ");
			}
		}
		if(fl==0)
		{
			printf("\n");
		}
	}
}



void writeHistory(char **hist,int cur) //-c -s
{
	int current=cur;
	int i=1;
	//printf("%s\n", hist[cur-2]);
	FILE *f;
	f=fopen("hist.txt","w");
	do
	{
		if(hist[cur])
		{
			fprintf(f,"%s",hist[cur]);
			i++;
		}
		cur=(cur+1)%1000;
	}while(cur!=current);
	fclose(f);
}


int history(char **hist,int cur,char **arguments,int arc,char *inp) //-c -s
{
	if(arc==1)
	{
		int current=cur;
		int i=1;
		//printf("%s\n", hist[cur-2]);
		do
		{
			if(hist[cur])
			{
				printf("%d %s", i,hist[cur]);
				i++;
			}
			cur=(cur+1)%1000;
		}while(cur!=current);
	}
	else if(arc==2 && strcmp(arguments[1],"-c")==0)
	{
		FILE *f;
		f=fopen("hist.txt","w");
		for(int i=0; i<1000; i++)
		{
			hist[i]=NULL;
		}
		fclose(f);
	}
	else if(strcmp(arguments[1],"-s")==0)
	{
		if(arc==2)
		{
			return cur;
		}
		else
		{
			inp=inp+11;
			hist[cur]=inp;
			cur=(cur+1)%1000;
			writeHistory(hist,cur);
		}
	}
	else
	{
		printf("Error: Invalid selected options\n");
	}	
	return cur;
}






int main(int argc, char const *argv[])
{
	int cur=0;
	char tmp[1000];
	char *hist[1000];
	for(int i=0; i<1000; i++)
	{
		hist[i]=NULL;
	}
	FILE *f;
	f=fopen("hist.txt","r");
	while(fgets(tmp,10000,f))
	{
		hist[cur]=strdup(tmp);
		cur=(cur+1)%1000;
	}
	fclose(f);




	while(1)
	{
		char inp[10000];
		char **arguments=malloc(100*sizeof(char*));
		pwd(0); //Printing pwd>>
		fgets(inp,10000,stdin);

		char *inpu;
		inpu=strdup(inp);

		free(hist[cur]);
		hist[cur]=strdup(inp);
		cur=(cur+1)%1000;
		writeHistory(hist,cur);

		char *x=strtok(inp," \t\r\n\a");
		int pos=0;
		for(int i=0; i<100; i++)
		{
			arguments[i]=NULL;
		}
		if(x==NULL)
		{
			continue;
		}
		while(x!=NULL)
		{
			// printf("%s\n", x);
			arguments[pos++]=x;
			x=strtok(NULL," \t\r\n\a");
		}

		if(strcmp(arguments[0],"exit")==0)
		{
			return 0;
		}
		else if(strcmp(arguments[0],"cd")==0)
		{
			cd(arguments);
		}
		else if(strcmp(arguments[0],"pwd")==0)
		{
			pwd(1);
		}
		else if(strcmp(arguments[0],"echo")==0)
		{
			echo(inpu,arguments,pos);
		}
		else if(strcmp(arguments[0],"history")==0)
		{
			cur=history(hist,cur,arguments,pos,inpu);
		}
		else
		{
			pid_t pid=fork();
			if (pid>0)
			{
				wait(NULL);
			}
			else if(pid<0)
			{
				printf("Fork Failure\n");
			}
			else
			{
				
				if(strcmp(arguments[0],"mkdir")==0)
				{
					if(execvp("./makeDir",arguments)==-1)
					{
						perror("sh");
					}
				}
				else if(strcmp(arguments[0],"ls")==0)
				{
					if(execvp("./ls",arguments)==-1)
					{
						perror("lsh");
					}					
				}
				else if(strcmp(arguments[0],"cat")==0)
				{
					if(execvp("./cat",arguments)==-1)
					{
						perror("sh");
					}
				}
				else if(strcmp(arguments[0],"rm")==0)
				{
					if(execvp("./rm",arguments)==0)
					{
						perror("sh");
					}
				}
				else if(strcmp(arguments[0],"date")==0)
				{
					if(execvp("./date",arguments)==0)
					{
						perror("sh");
					}
				}
				else
				{
					printf("ERROR: Invalid command\n");
					exit(1);
				}
			}
		}
		free(arguments);
	}
	return 0;
}