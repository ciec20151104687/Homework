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
		printf("编号\t|纬度 \t\t|经度\t\t|日期\t\t|时间\n");
		fprintf(p, "编号,纬度,经度,日期,时间\n");		
		fseek(fp, 0, SEEK_SET);
		fread(m, 1, 591, fp);
		char *str1max = "maxlat", *str2max = "maxlon",  *ptr1max, *ptr2max ;
		char m1max[20], m2max[20];
		ptr1max = strstr(m, str1max);
		ptr2max = strstr(m, str2max);
		strncpy(m1max, ptr1max+8, 9);
		strncpy(m2max, ptr2max+8, 10);
		m1max[9] = '\0';
		m2max[10] = '\0';
		printf("最大值\t|%s\t|%s\n", m1max, m2max);
		fprintf(p, "最大值,%s,%s\n", m1max, m2max);
		fseek(fp, 0, SEEK_SET);
		fread(m, 1, 591, fp);
		char *str1min = "minlat", *str2min = "minlon", *ptr1min, *ptr2min;
		char m1min[20], m2min[20];
		ptr1min = strstr(m, str1min);
		ptr2min = strstr(m, str2min);
		strncpy(m1min, ptr1min+8, 9);
		strncpy(m2min, ptr2min+8, 10);
		m1min[9] = '\0';
		m2min[10] = '\0';
		printf("最小值\t|%s\t|%s\n", m1min, m2min);
		fprintf(p, "最小值,%s,%s\n", m1min, m2min);
		fseek(fp, 591, SEEK_SET);
		fread(m, 1, len - 591, fp);
		int i = 0, j = 1;
		while (i <= len - 591 - 52)
		{		
			char *str1 = "lat", *str2 = "lon", *str3 = "<time>", *str4 = "T";
			char *ptr1, *ptr2, *ptr3, *ptr4;
			char m1[20], m2[20], m3[20], m4[20];
			ptr1 = strstr(m, str1);
			ptr2 = strstr(m, str2);
			ptr3 = strstr(m, str3);
			ptr4 = strstr(m, str4);
			strncpy(m1, ptr1 + 5 + i, 9);
			strncpy(m2, ptr2 + 5 + i, 10);
			strncpy(m3, ptr3 + 6 + i, 10);
			strncpy(m4, ptr4 + 1 + i, 8);
			m1[9] = '\0';
			m2[10] = '\0';
			m3[10] = '\0';
			m4[8] = '\0';
			printf("%d\t|%s \t|%s\t|%s\t|%s\n", j, m1, m2, m3, m4);
			fprintf(p, "%d,%s,%s,%s,%s\n", j, m1, m2, m3, m4);
			i = i + 94;
			j++;
		}
	}
	fclose(fp);
	fclose(p);
	free(m);
	return 0;
}