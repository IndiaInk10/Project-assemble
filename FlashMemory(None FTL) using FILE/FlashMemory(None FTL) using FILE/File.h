#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCKSIZE 16384 // sizeof(1 Block)
#define SECTORSIZE 512 // sizeof(1 Sector)
#define SECTORSIZE_BLOCK 32 // 1 BLOCK(16384B) / 1 Sector(512B) = 32

int fSize; // flashMemoryRead���� �Էµ� ���� ���� ������ ������ ������� �˱� ���� ���� ������ ũ��(FlashMemory�� �뷮)
char data[SECTORSIZE]; // �� ������ ���� �о���� ���� ���ڿ�

void flashMemoryInit(FILE *file, int SN); // ������ ������ �Է¹޾� �ش� ������ ������ŭ ���Ͽ� �޸𸮸� �Ҵ� ������ 32 * x

char* flashMemoryRead(FILE *FlashMemory, int PSN); //  ������ �����ּҸ� �а� �ش� ���� �������ش�. ���������� ���� �ִ� �κ��� data[509] �κ��̴�

void flashMemoryWrite(FILE *FlashMemory, int PSN, char data); // ������ �����ּҸ� �а� ���� wrtie ������ �Ǿ������� Ȯ��, �Ǿ����� ��� overwrite error �ƴ� ��� ���� ����

void flashMemoryErase(FILE *FlashMemory, int PBN); // ����� �����ּҸ� ã�� �ش� ����� �����. ���������� �ʱⰪ�� 0���� �����߱� ������ erase ����� 0�� ���� ���Եȴ�