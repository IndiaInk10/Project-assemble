#include "Func.h"
#include <ctype.h>
#include <stdbool.h>

#define COMMANDSTRING 15 // maximum length
#define MEGABYTE 1048576 // sizeof(1 MB)

void getCommand(FILE *file) // get command
{
	char command[COMMANDSTRING];
	memset(command, 0, COMMANDSTRING);
	bool bInit = false;

	char *context;
	char *tok[2];

	while (1)
	{
		printf("Insert command\n");
		printf("Command list: init, read, write, erase, exit\n");
		printf("ex) init num(Megabyte), read num(Sector address), write num(Sector address) data, erase num(Block address)\n");
		printf("    init 5, read 5, write 5 A, erase 5, exit\n");
		printf(">> ");
		scanf_s("%[^\n]s", command, COMMANDSTRING);

		context = command;
		tok[0] = strtok_s(context, " ", &context);

		for (unsigned int i = 0; i < strlen(tok[0]); i++)
		{
			if (tok[0][i] == toupper(tok[0][i]))
				tok[0][i] = tolower(tok[0][i]);
		}

		if (strcmp(tok[0], "exit") == 0) // exit이 입력될 경우 종료
		{
			return;
		}
		else if (bInit == false)
		{
			if (strcmp(tok[0], "init") == 0)
			{
				tok[1] = context;

				if (atoi(tok[1]) != 0 || strcmp(tok[1], "0") == 0)
				{
					init(file, atoi(tok[1]));
					printf("%d MegaBytes Flash Memory\n", atoi(tok[1]));
					bInit = true;
					while (getchar() != '\n');
				}
				else
				{
					printf("Invalid command input\n");
					while (getchar() != '\n');
				}
			}
			else
			{
				printf("Invalid command input\n");
				while (getchar() != '\n');
			}
		}
		else
		{
			if (strcmp(tok[0], "read") == 0)
			{
				tok[1] = context;

				if (atoi(tok[1]) != 0 || strcmp(tok[1], "0") == 0)
				{
					Flash_read(file, atoi(tok[1]));
					while (getchar() != '\n');
				}
				else
				{
					printf("Invalid command input\n");
					while (getchar() != '\n');
				}
			}
			else if (strcmp(tok[0], "write") == 0)
			{
				tok[1] = strtok_s(context, " ", &context);
				tok[2] = context;

				if ((atoi(tok[1]) != 0 || strcmp(tok[1], "0") == 0) && strcmp(tok[2], "") != 0)
				{
					Flash_write(file, atoi(tok[1]), tok[2][0]);
					while (getchar() != '\n');
				}
				else
				{
					printf("Invalid command input\n");
					while (getchar() != '\n');
				}
			}
			else if (strcmp(tok[0], "erase") == 0)
			{
				tok[1] = context;

				if (atoi(tok[1]) != 0 || strcmp(tok[1], "0") == 0)
				{
					Flash_erase(file, atoi(tok[1]));
					while (getchar() != '\n');
				}
				else
				{
					printf("Invalid command input\n");
					while (getchar() != '\n');
				}
			}
			else
			{
				printf("Invalid command input\n");
				while (getchar() != '\n');
			}
		}
	}
}

void init(FILE *file, int size) // create num MB Flash Memory, num is MB
{
	fSize = size * MEGABYTE; //  총 파일의 크기(FlashMemory의 용량)
	size = (size * MEGABYTE) / 512; // MB를 B단위로 바꾸어 섹터 하나의 용량으로 나누어 줌; 섹터의 갯수

	flashMemoryInit(file, size); // size = sector num
}
void Flash_read(FILE *FlashMemory, int PSN) // read page data, num is sector address
{
	char* sectorData = flashMemoryRead(FlashMemory, PSN);

	if (sectorData != NULL)
	{
		printf("%d Block %d Sector Data: %c\n", PSN/SECTORSIZE_BLOCK, PSN%SECTORSIZE_BLOCK, sectorData[509]);
	}
	else
	{
		printf("nonexistent sector\n");
	}
}
void Flash_write(FILE *FlashMemory, int PSN, char data) // write data at sector, num is sector address
{
	flashMemoryWrite(FlashMemory, PSN, data);
}
void Flash_erase(FILE *FlashMemory, int PBN) // erase block, num is sector address
{
	flashMemoryErase(FlashMemory, PBN);
}