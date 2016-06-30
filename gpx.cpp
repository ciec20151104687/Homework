// ConsoleApplication2.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	char *s;
	int len = NULL;
	if((fp = fopen("C:\\Users\\lyh78\\Desktop\\new\\export.gpx", "rb"))==0)
	{
		printf("error\n");
		return(-1);
	}
	fseek(fp, 0, SEEK_END);
	len = ftell(fp);
	s = (char *)malloc(len);
	fseek(fp, 0, SEEK_SET);
	while (fread(s, 1, len, fp))
	{
		printf("%s", s);
	}
	
	fclose(fp);
    return 0;
}	 
