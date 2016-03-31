#include "stdafx.h"

void SaveImage(char* szPathName, void* lpBits, int w, int h) {
	FILE *pFile = fopen(szPathName, "wb");
	fwrite(lpBits, 1, w*h, pFile);
	fclose(pFile);
}