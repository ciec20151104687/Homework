// gpx.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"


int _tmain(int argc, _TCHAR* argv[])
{
	FILE *fp;
	FILE *p;
	char *m;
	int len = NULL;
	if ((fp = fopen("C:\\Users\\lyh78\\Desktop\\new\\export.gpx", "rb")) == 0)
	{
		printf("error\n");
		return(-1);
	}
	else
	{
		p = fopen("C:\\Users\\lyh78\\Desktop\\new\\gpx.csv", "wb");
		fseek(fp, 0, SEEK_END);
		len = ftell(fp);
		m = (char *)malloc(len);
		printf("|纬度 \t\t|经度\t\t|时间\n");
		fprintf(p, "纬度,经度,时间\n");		
		                                            //max
		fseek(fp, 0, SEEK_SET);
		fread(m, 1, 591, fp);
		char *str1max = "maxlat", *str2max = "maxlon",  *ptr1max, *ptr2max ;
		char m1max[20], m2max[20];
		ptr1max = strstr(m, str1max);
		ptr2max = strstr(m, str2max);
		strncpy(m1max, ptr1max, 18);
		strncpy(m2max, ptr2max, 19);
		m1max[18] = '\0';
		m2max[19] = '\0';
		printf("|%s\t\t%s\n", m1max, m2max);
		fprintf(p, "%s,%s\n", m1max, m2max);
													//min
		fseek(fp, 0, SEEK_SET);
		fread(m, 1, 591, fp);
		char *str1min = "minlat", *str2min = "minlon", *ptr1min, *ptr2min;
		char m1min[20], m2min[20];
		ptr1min = strstr(m, str1min);
		ptr2min = strstr(m, str2min);
		strncpy(m1min, ptr1min, 18);
		strncpy(m2min, ptr2min, 19);
		m1min[18] = '\0';
		m2min[19] = '\0';
		printf("|%s\t\t%s\n", m1min, m2min);
		fprintf(p, "%s,%s\n", m1min, m2min);
													//
		fseek(fp, 591, SEEK_SET);
		fread(m, 1, len - 591, fp);
		int i = 0;
		while (i <= len - 591 - 52)
		{		
			char *str1 = "lat", *str2 = "lon", *str3 = "<time>", *ptr1, *ptr2, *ptr3;
			char m1[20],m2[20],m3[30];
			ptr1 = strstr(m, str1);
			ptr2 = strstr(m, str2);
			ptr3 = strstr(m, str3);
			strncpy(m1, ptr1+5+i, 9);
			strncpy(m2, ptr2+5+i, 10);
			strncpy(m3, ptr3+6+i, 20);
			m1[9] = '\0';
			m2[10] = '\0';
			m3[20] = '\0';
			printf("|%s \t|%s\t|%s\n", m1, m2, m3);
			fprintf(p,"%s,%s,%s\n", m1, m2, m3);
			i = i + 94;
		}
	}
	fclose(fp);
	free(m);
	fclose(p);
	return 0;
}
