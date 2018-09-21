// disk_wr.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <tchar.h>
#include <winioctl.h>
#include <ntddscsi.h>


int _tmain (int Argc, _TCHAR *argv[])
{
	int i = 0;
	unsigned char Buffer[512] = {0};
	HANDLE hDev;
	DWORD dwRet = 0;

	hDev=CreateFile("\\\\.\\PHYSICALDRIVE2",GENERIC_READ,FILE_SHARE_READ,0,OPEN_EXISTING,0,0);	//"\\\\.\\G:"
	if (hDev == INVALID_HANDLE_VALUE){
		printf("CreatFile Error\n");
	}

	
	SetFilePointer(hDev, NULL, NULL, FILE_BEGIN);
	ReadFile(hDev,Buffer,512,&dwRet,NULL);
	if (dwRet < 0){
		printf("ReadFile Error\n");
	}
	printf("dwRet:%d\r\n",dwRet);
	for(int i=0; i< 512; i++){
		printf("%02x " ,Buffer[i]);
	}

	CloseHandle(hDev);
	scanf("%d",&i);
	return 1;
}