#include "stdafx.h"
#include "stdlib.h"
#include "stdio.h"

void print(char arr[], char *pt);
extern int test_base64();
extern int test_data_type();
int main(int argc, _TCHAR* argv[])
{
	test_base64();

	printf("++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n"); 
	
	test_data_type();
	return 0;
}
