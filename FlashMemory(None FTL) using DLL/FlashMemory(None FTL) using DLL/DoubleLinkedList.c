#include "DoubleLinkedList.h"

DLL* createList() // malloc NAND Flash Memory
{
	DLL* newList = (DLL*)malloc(sizeof(DLL));
	newList->head = createNode();
	newList->tail = createNode();
	newList->count = 0;

	return newList;
}
NODE* createNode() // malloc Block
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	newNode->lLink = NULL, newNode->rLink = NULL;
	memset(newNode->data, '0', SECTORSIZE_BLOCK);

	return newNode;
}

bool bEmpty(DLL *list)
{
	if (list->head->rLink == NULL && list->tail->lLink == NULL && list->count == 0)
		return true;
	else
		return false;
}
void insertNode(DLL *list, int BN) // set Blocks into NAND Flassh Memory
{
	int counting = 0;

	while (counting != BN)
	{
		if (bEmpty(list) == true)
		{
			NODE* newNode = createNode();
			newNode->Address = counting++;

			list->head->rLink = newNode;
			list->tail->lLink = newNode;
			newNode->lLink = list->head;
			newNode->rLink = list->tail;
		}
		else
		{
			NODE* newNode = createNode();
			newNode->Address = counting++;

			list->tail->lLink->rLink = newNode;
			newNode->lLink = list->tail->lLink;
			newNode->rLink = list->tail;
			list->tail->lLink = newNode;
		}
	}
	list->count = counting;
}

int getCount(DLL *list) // get Block Num
{
	return list->count;
}

int addressOfBlock(int PSN) // change sector num to Block address
{
	return PSN / SECTORSIZE_BLOCK;
}
char* searchData(DLL *list, int PSN) // read, overwrite Error(sector), num is sector address
{
	NODE* search = list->head->rLink;

	while (search->rLink != list->tail)
	{
		if (search->Address == addressOfBlock(PSN))
			return &(search->data[PSN - ((search->Address * SECTORSIZE_BLOCK) + 1)]); // Succeeded to search(sector)
		else
		{
			search = search->rLink;
			continue;
		}
	}

	return NULL; // Failed to search(sector)
}
void modifyNode(DLL *list, int PSN, char data) // write, num is sector address
{
	char* modify = searchData(list, PSN);

	if (modify != NULL) // Succeeded to search(dataOfSector)
	{
		if (*modify == '0')
		{
			*modify = data;
			printf("done\n");
		}
		else
			printf("overwrite error\n");
	}
	else
		printf("nonexistent sector\n");
}
void initNode(DLL *list, int PBN) // erase Block(after search(Block)), num is block address
{
	NODE* search = list->head->rLink;

	while (search != list->tail)
	{
		if (search->Address == PBN)
			break; // Succeeded to search(Block)
		else
		{
			search = search->rLink;
			continue;
		}		
	}
	
	if (search != list->tail)
	{
		memset(search->data, '0', SECTORSIZE_BLOCK);
		printf("%dth block erase\n", search->Address);
	}
	else
		printf("nonexistent block\n");
}