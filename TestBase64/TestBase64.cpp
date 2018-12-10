// TestBase64.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "stdlib.h"
#include "string.h"
#include "stdio.h"

extern "C" int __declspec(dllimport) Base64decode_len(const char *bufcoded);

extern "C" int __declspec(dllimport) Base64decode(char *bufplain, const char *bufcoded);

extern "C" int __declspec(dllimport) Base64encode_len(int src_len);

extern "C" int __declspec(dllimport) Base64encode(char *encoded, const char *string, int len);


int test_base64()
{
	char userName[]="张三";
	char *pass = "JITOSAdminPass";

	int src_len = strlen(pass);
	int dst_len = Base64encode_len(src_len);

	char* dst = (char*)malloc(dst_len);

	if(dst == NULL){
		printf("内存分配失败");
		return 0;
	}
	
	printf("Password:%s, src_len:%d, dst_len:%d\n", pass, src_len, dst_len);

	Base64encode(dst, pass, src_len);

	printf( "We are on iteration: %d, userName: %s, Passwd: %s\n",1, userName, dst);

	//base64解码
	int decode_len = Base64decode_len(dst);

	char *decoded = (char*)malloc(decode_len);

	if(decoded == NULL){
		printf("内存分配失败\n");
		return 0;
	}
	memset(decoded, 0, decode_len);
	Base64decode(decoded, dst);

	printf("Secret:%s\n", decoded);

	free(dst);
	free(decoded);

	return 0;
}

