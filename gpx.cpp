#include<stdio.h>
#include <string.h>
#include <stdlib.h>
int main()
{
	FILE *fp;
	char str[80];
	fp=fopen("export.gpx", "r");
	if(fp==NULL)
	{
		printf("error");
		exit(-1);
	}
	else
	{
		while(fgets(str,20,fp))
		{
			printf("%s",str);
			
		}
		fclose(fp);
	}
	return 0;
}
						            
					 
