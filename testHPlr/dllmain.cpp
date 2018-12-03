// dllmain.cpp : Defines the entry point for the DLL application.
#include "D:\Loadrunner11\include\lrun.h"
#include "stdafx.h"
#include "base64.h"

//------debug
void infos(char *str){
	lr_output_message("parameter is %s", str);
}
void infod(int len){
	lr_output_message("parameter int is %d", len);
}
/**
* 动态库入口
*/
extern "C"  BOOL WINAPI DllMain(
	HINSTANCE hinstDLL,  // handle to DLL module
	DWORD fdwReason,     // reason for calling function
	LPVOID lpReserved )  // reserved
{
	// Perform actions based on the reason for calling.
	switch( fdwReason ) 
	{ 
	case DLL_PROCESS_ATTACH:
		// Initialize once for each new process.
		// Return FALSE to fail DLL load.
		break;

	case DLL_THREAD_ATTACH:
		// Do thread-specific initialization.
		break;

	case DLL_THREAD_DETACH:
		// Do thread-specific cleanup.
		break;

	case DLL_PROCESS_DETACH:
		// Perform any necessary cleanup.
		break;
	}
	return TRUE;  // Successful DLL_PROCESS_ATTACH.
}

/**
 * 自定义导出函数
 */
extern "C" {
	int __declspec(dllexport) Init (char *userName, char *pass)
	{
		int src_len = strlen(pass);
		int dst_len = Base64encode_len(src_len);

		char* dst = (char*)malloc(dst_len);
		//-----------------------------------

		const unsigned char *pwd = (const unsigned char *)"JITOSAdminPass";
		//char *mutual_dst;
		//size_t *mutual_dst_len;

		lr_output_message("pass:%s, src_len:%d, dst_len:%d", pass, src_len, dst_len);

		int encoded_len = Base64encode(dst, pass, src_len);
		
		lr_output_message( "We are on iteration: %s, userName: %s, Passwd: %s", lr_eval_string("{iter}" ), (char*)userName, dst);
		
		//base64解码
		int decode_len = Base64decode_len(dst);
		//int Base64decode(char *bufplain, const char *bufcoded)
		char *decoded = (char*)malloc(decode_len);
				
		if(decoded == NULL){
			infos("内存分配失败");
			return 0;
		}
		memset(decoded, 0, decode_len);
		Base64decode(decoded, dst);

		lr_output_message("Secret:%s", decoded);

		free(dst);
		free(decoded);

		//mutual_dst = base64_encode(pwd, src_len, mutual_dst_len);
		//lr_output_message("Base64 passwd:%s", mutual_dst);
		
		return 0;
	}
	int __declspec(dllexport) Run (void *p)
	{
		const char *str = lr_eval_string("<name>");
		lr_output_message("in run and parameter is %s", str);
		return 0;
	}
	int __declspec(dllexport) End (void *p)
	{
		lr_output_message("in end");
		return 0;
	}

}
