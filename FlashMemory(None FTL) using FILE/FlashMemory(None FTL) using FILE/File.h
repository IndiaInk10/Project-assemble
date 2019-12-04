#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCKSIZE 16384 // sizeof(1 Block)
#define SECTORSIZE 512 // sizeof(1 Sector)
#define SECTORSIZE_BLOCK 32 // 1 BLOCK(16384B) / 1 Sector(512B) = 32

int fSize; // flashMemoryRead에서 입력된 섹터 값이 파일의 범위를 벗어나는지 알기 위해 구한 파일의 크기(FlashMemory의 용량)
char data[SECTORSIZE]; // 한 섹터의 값을 읽어오기 위한 문자열

void flashMemoryInit(FILE *file, int SN); // 섹터의 갯수를 입력받아 해당 섹터의 갯수만큼 파일에 메모리를 할당 갯수는 32 * x

char* flashMemoryRead(FILE *FlashMemory, int PSN); //  섹터의 물리주소를 읽고 해당 값을 리턴해준다. 실질적으로 값이 있는 부분은 data[509] 부분이다

void flashMemoryWrite(FILE *FlashMemory, int PSN, char data); // 섹터의 물리주소를 읽고 값이 wrtie 연산이 되었는지를 확인, 되어있을 경우 overwrite error 아닐 경우 값을 대입

void flashMemoryErase(FILE *FlashMemory, int PBN); // 블록의 물리주소를 찾아 해당 블록을 지운다. 개인적으로 초기값을 0으로 설정했기 때문에 erase 연산시 0의 값이 대입된다