#include <stdio.h>
#include <time.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	time_t t;
	time(&t);
	if(argc==1)
	{
		char *a;
		a=ctime(&t);
		a[strlen(a)-6]='\0';
		printf("%s IST %s", a,a+20);
	}
	else
	{
		if(argc==3 && ((strcmp(argv[1],"-R")==0 && strcmp(argv[2],"-u")==0)||(strcmp(argv[1],"-u")==0 && strcmp(argv[2],"-R")==0)))
		{
			char *a;
			a=asctime(gmtime(&t));
			a[strlen(a)-1]=' ';
			printf("%s+0000\n",a );
		}
		else if(strcmp(argv[1],"-R")==0)
		{
			char *a;
			a=ctime(&t);
			a[strlen(a)-1]=' ';
			printf("%s +0530\n", a);
		}
		else if(strcmp(argv[1],"-u")==0)
		{
			char *a;
			a=asctime(gmtime(&t));
			a[strlen(a)-6]='\0';
			printf("%s UTC %s", a,a+20);
		}
		else
		{
			printf("Error: Invalid selected options\n");
		}
	}
	return 0;
}