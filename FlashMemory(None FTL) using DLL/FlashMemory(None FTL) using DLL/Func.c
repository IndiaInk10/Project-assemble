#include "Func.h"
#include <ctype.h> // tolower, toupper function

#define COMMANDSTRING 15 // maximum length
#define MEGABYTE 1048576 // sizeof(1 MB)
#define BLOCKSIZE 16384 // sizeof(1 Block)

void getCommand(DLL *list) // get command
{
	char command[COMMANDSTRING];
	memset(command, 0, COMMANDSTRING);

	char *context;
	char *tok[2];

	while (1)
	{
		printf("Insert command\n");
		printf("Command list: init, read, write, erase\n");
		printf("ex) init num(Megabyte), read num(Sector address), write num(Sector address) data, erase num(Block address)\n");
		printf("    init 5, read 5, write 5 A, erase 5\n");
		printf(">> ");
		scanf_s("%[^\n]s", command, COMMANDSTRING);
		
		context = command;
		tok[0] = strtok_s(context, " ", &context);

		for (unsigned int i = 0; i < strlen(tok[0]); i++)
		{
			if (tok[0][i] == toupper(tok[0][i]))
				tok[0][i] = tolower(tok[0][i]);
		}

		if (list == NULL)
		{
			if (strcmp(tok[0], "init") == 0)
			{
				tok[1] = context;

				if (atoi(tok[1]) != 0 || strcmp(tok[1], "0") == 0)
				{
					list = init(list, atoi(tok[1]));
					printf("%d MegaBytes Flash Memory\n", atoi(tok[1]));
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
					Flash_read(list, atoi(tok[1]));
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
					Flash_write(list, atoi(tok[1]), tok[2][0]);
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
					Flash_erase(list, atoi(tok[1]));
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

DLL* init(DLL *list, int size) // create num MB Flash Memory, num is MB
{
	size = (size * MEGABYTE) / BLOCKSIZE; // MB를 B단위로 바꾸어 블럭 하나의 용량으로 나누어 줌; 블럭의 갯수

	list = createList(); // list malloc and init to 0
	insertNode(list, size); // init FlashMemory(set Blocks)

	return list;
}
void Flash_read(DLL *FlashMemory, int PSN) // read sector data, num is sector address
{
	char* sectorData = searchData(FlashMemory, PSN);

	if (sectorData != NULL)
	{
		printf("%d Block %d Sector Data: %c\n", addressOfBlock(PSN), PSN - ((addressOfBlock(PSN) * SECTORSIZE_BLOCK) + 1), *sectorData);
	}
	else
	{
		printf("nonexistent sector\n");
	}
}
void Flash_write(DLL *FlashMemory, int PSN, char data) // write data at sector, num is sector address
{
	modifyNode(FlashMemory, PSN, data);
}
void Flash_erase(DLL *FlashMemory, int PBN) // erase block, num is sector address
{
	initNode(FlashMemory, PBN);
}