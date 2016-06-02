#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>



#ifdef _DEBUG
#define TRACE(s) OutputDebugString(s)
#else // _DEBUG
#define TRACE(s)
#endif // _DEBUG

#define ASSERT(condition) if(!(condition)){\
char filename[100], line[10];\
sprintf(filename, "%s", __FILE__);\
sprintf(line, "%d", __FILE__);\
TRACE("FileName: ");\
TRACE(filename);\
TRACE(" ");\
TRACE("Line: ");\
TRACE(line);\
}
//,TRACE(" "),TRACE(""),TRACE(" "),TRACE(__LINE__)

int main()
{

	ASSERT(0)

	getchar();
	return 0;
}