#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"

void print(char arr[], char *pt);

int main(int argc, _TCHAR* argv[])
{
	char *t = "abc";
	printf("pointer is %s\n", t);
	printf("addr of pointer is %d\n", &t);
	
	char arr[20];
	char *pt = (char *)malloc(sizeof(char) * 20);
	//原始类型
	printf("sizeof original arr :%d\n", sizeof(arr));
	printf("sizeof original p :%d\n", sizeof(pt));
	//参数传递后
	print(arr, pt);
	//基础数据类型（primative）
	unsigned char byte;
	printf("sizeof byte :%d\n", sizeof(byte));
	printf("sizeof char :%d\n", sizeof(char));

	short _2byte;
	printf("sizeof short :%d\n", sizeof(_2byte));
	printf("sizeof int :%d\n", sizeof(int));

	printf("sizeof float :%d\n", sizeof(float));
	printf("sizeof double :%d\n", sizeof(double));

	system("pause");
	
	return 0;
}

void print(char arr[], char *pt) 
{
	printf("sizeof arr :%d\n", sizeof(arr));
	printf("sizeof pt :%d\n", sizeof(pt));
}
