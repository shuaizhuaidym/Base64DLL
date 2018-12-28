// TestBase64DynamicLink.cpp : Defines the entry point for the console application.
//
#include "stdio.h"
#include "stdafx.h"
#include "stdarg.h"

#include "windows.h"
#include "tchar.h"

typedef int (*Func_Base64encode_len)(int src_len);

typedef int (*Func_Base64encode)(char *encoded, const char *string, int len);

typedef int (*Func_Base64decode_len)(const char *bufcoded);

typedef int (*Func_Base64decode)(char *bufplain, const char *bufcoded);


void log(const char *cmd, ...)
{
    printf("%s %s ", __DATE__, __TIME__);
    va_list args;       //����һ��va_list���͵ı������������浥������
    va_start(args,cmd); //ʹargsָ��ɱ�����ĵ�һ������
    vprintf(cmd,args);  //������vprintf�ȴ�V�ģ�vprintf����ר���������տɱ������printf�汾 
    va_end(args);       //�����ɱ�����Ļ�ȡ
	printf("\n");       //�������
}


int _tmain(int argc, _TCHAR* argv[])
{

	Func_Base64encode_len Base64encode_len = NULL;
	Func_Base64encode Base64encode = NULL;

	Func_Base64decode_len Base64decode_len = NULL;
	Func_Base64decode Base64decode = NULL;

	char *userName = "������";

	char *base64UserName;
	char *decoded;

	int encode_len;
	int decode_len;

	char *libName = "Base64.dll";

	LPCWSTR lname =  L"Base64.dll";

	HINSTANCE hlib = LoadLibrary(lname);

	if(hlib == NULL){
		log("Error:unable to load dll %s", libName);
		return 1;
	}
	Base64encode_len = (Func_Base64encode_len)GetProcAddress(hlib, "Base64encode_len");

	if(Base64encode_len == NULL){
		log("Error:unable to load function [%s] from dll [%s]", "Base64encode_len", libName);
		return 1;
	}
	log("All initialize work is ok.");

	encode_len = Base64encode_len(strlen(userName));
	log("User name: %s, length of base 64 user name: %d", userName, encode_len);

	Base64encode = (Func_Base64encode)GetProcAddress(hlib, "Base64encode");
	if(Base64encode == NULL){
		log("Error:unable to load function [%s] from dll [%s]", "Base64encode", libName);
		return 1;
	}
	base64UserName = (char*)malloc(encode_len);
	Base64encode(base64UserName, userName, strlen(userName));
	log("Base64Encoded user name:%s", base64UserName);
	
	Base64decode_len = (Func_Base64decode_len)GetProcAddress(hlib, "Base64decode_len");
	if(Base64decode_len == NULL){
		log("Error:unable to load function [%s] from dll [%s]", "Base64decode_len", libName);
		return 1;
	}
	Base64decode = (Func_Base64decode)GetProcAddress(hlib, "Base64decode");
	if(Base64decode == NULL){
		log("Error:unable to load function [%s] from dll [%s]", "Base64decode", libName);
		return 1;
	}
	decode_len = Base64decode_len(base64UserName);
	decoded = (char*)malloc(decode_len);
	Base64decode(decoded, base64UserName);

	log("Base64 decoded user name:%s", decoded);
	
	free(base64UserName);
	free(decoded);

	system("pause");
	return 0;
}

