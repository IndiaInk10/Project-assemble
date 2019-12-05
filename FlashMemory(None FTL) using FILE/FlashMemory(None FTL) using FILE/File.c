#include "File.h"

void flashMemoryInit(FILE *file, int SN)
{
	fopen_s(&file, "FlashMemory.txt", "w+t");

	for (int i = 0; i < SN; i++)
	{
		fprintf(file, "%0510c\n", '0'); // ���� �����͸� �ٷ�� ���� 510ĭ�̰�, ���๮�ڰ� 2ĭ(2����Ʈ)�� ��
	}

	fclose(file);
}

char* flashMemoryRead(FILE *FlashMemory, int PSN)
{
	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	PSN = (--PSN) * SECTORSIZE; // ������ �뷮 ��ŭ�� ������ ������ ���� ��ġ�� ã�´�
	
	if (PSN <= fSize && PSN >= 0) // ������ ���� �� = ���Ͱ� �����Ѵ�
	{
		fseek(FlashMemory, PSN, SEEK_SET);
		fscanf_s(FlashMemory, "%s", &data, sizeof(data));
		fclose(FlashMemory);

		return data;
	}
	else // ������ ���� �� = ���Ͱ� �������� �ʴ´�
	{
		fclose(FlashMemory);
		return NULL;
	}
}

void flashMemoryWrite(FILE *FlashMemory, int PSN, char data)
{
	char* SectorData = flashMemoryRead(FlashMemory, PSN);

	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	if (SectorData != NULL) // ������ ���� �� = ���Ͱ� �����Ѵ�
	{
		if (strcmp(&SectorData[509], "0") == 0) // �ʱ�ȭ ������ �����Ǿ� �ִ�.
		{
			PSN = (--PSN) * SECTORSIZE;
			fseek(FlashMemory, PSN, SEEK_SET);
			fprintf(FlashMemory, "%0510c\n", data);
			fclose(FlashMemory);

			printf("done\n");
		}
		else //  �ʱ�ȭ ���� �ƴ� write ������ �Ͼ ���
		{
			fclose(FlashMemory);
			printf("overwrite error\n");
		}
	}
	else // ������ ���� �� = ���Ͱ� �������� �ʴ´�
	{
		fclose(FlashMemory);
		printf("nonexistent sector\n");
	}
}

void flashMemoryErase(FILE *FlashMemory, int PBN)
{
	fopen_s(&FlashMemory, "FlashMemory.txt", "r+t");

	PBN = (--PBN) * BLOCKSIZE; //  �� �뷮 ��ŭ�� ������ ���� ���� ��ġ�� ã�´�

	if (PBN <= fSize && PBN >= 0) // ������ ���� �� = ���� �����Ѵ�
	{
		fseek(FlashMemory, PBN, SEEK_SET);
		for (int i = 0; i < SECTORSIZE_BLOCK; i++)
		{
			fprintf(FlashMemory, "%0510c\n", '0'); 
		}
		printf("%dth block erase\n", PBN/BLOCKSIZE);
		fclose(FlashMemory);
	}
	else // ������ ���� �� = ���� �������� �ʴ´�
	{
		fclose(FlashMemory);
		printf("nonexistent block\n");		
	}
}