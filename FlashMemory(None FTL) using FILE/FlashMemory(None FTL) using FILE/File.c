#include "File.h"

void flashMemoryInit(FILE *file, int SN)
{
	fopen_s(&file, "FlashMemory.txt", "w+t");

	for (int i = 0; i < SN; i++)
	{
		fprintf(file, "%0510c\n", '0'); // 실제 데이터를 다루는 폭은 510칸이고, 개행문자가 2칸(2바이트)로 들어감
	}

	fclose(file);
}

char* flashMemoryRead(FILE *FlashMemory, int PSN)
{
	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	PSN *= SECTORSIZE; // 섹터의 용량 만큼을 곱해줘 섹터의 시작 위치를 찾는다

	fseek(FlashMemory, PSN, SEEK_SET);
	
	if (ftell(FlashMemory) <= fSize) // 파일의 범위 안 = 섹터가 존재한다
	{
		fscanf_s(FlashMemory, "%s", &data, sizeof(data));
		fclose(FlashMemory);

		return data;
	}
	else // 파일의 범위 밖 = 섹터가 존재하지 않는다
	{
		fclose(FlashMemory);
		return NULL;
	}
}

void flashMemoryWrite(FILE *FlashMemory, int PSN, char data)
{
	char* SectorData = flashMemoryRead(FlashMemory, PSN);

	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	if (SectorData != NULL) // 파일의 범위 안 = 섹터가 존재한다
	{
		if (strcmp(&SectorData[509], "0") == 0) // 초기화 값으로 설정되어 있다.
		{
			PSN *= SECTORSIZE;
			fseek(FlashMemory, PSN, SEEK_SET);
			fprintf(FlashMemory, "%0510c\n", data);
			fclose(FlashMemory);

			printf("done\n");
		}
		else //  초기화 값이 아닌 write 연산이 일어난 경우
		{
			fclose(FlashMemory);
			printf("overwrite error\n");
		}
	}
	else // 파일의 범위 밖 = 섹터가 존재하지 않는다
	{
		fclose(FlashMemory);
		printf("nonexistent sector\n");
	}
}

void flashMemoryErase(FILE *FlashMemory, int PBN)
{
	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	PBN *= BLOCKSIZE; //  블럭 용량 만큼을 곱해줘 블럭의 시작 위치를 찾는다

	fseek(FlashMemory, PBN, SEEK_SET);

	if (ftell(FlashMemory) <= fSize) // 파일의 범위 안 = 블럭이 존재한다
	{
		for (int i = 0; i < SECTORSIZE_BLOCK; i++)
		{
			fprintf(FlashMemory, "%0510c\n", '0');
		}
		printf("%dth block erase\n", PBN/BLOCKSIZE);
		fclose(FlashMemory);
	}
	else // 파일의 범위 밖 = 블럭이 존재하지 않는다
	{
		fclose(FlashMemory);
		printf("nonexistent block\n");		
	}
}