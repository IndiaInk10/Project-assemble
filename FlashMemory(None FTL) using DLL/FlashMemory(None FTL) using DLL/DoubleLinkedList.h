#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

#define SECTORSIZE_BLOCK 32 // 1 BLOCK(16384B) / 1 Sector(512B) = 32

typedef struct node { // Block
	struct node *lLink;
	struct node *rLink;
	
	int Address; // physcial Address of Block
	char data[SECTORSIZE_BLOCK]; // Sector, 32 Sector = 1 Block
}NODE;

typedef struct doubleLinkedList { // NAND Flash Memory
	NODE *head;
	NODE *tail;

	int count; // Block Num
}DLL;

DLL* createList(); // malloc NAND Flash Memory
NODE* createNode(); // malloc Block

bool bEmpty(DLL *list);
void insertNode(DLL *list, int BN); // set Blocks into NAND Flassh Memory

int getCount(DLL *list); // get Block Num

int addressOfBlock(int PSN); // change sector num to Block address
char* searchData(DLL *list, int PSN); // read, overwrite Error(sector), num is sector address
void modifyNode(DLL *list, int PSN, char data); // write, num is sector address
void initNode(DLL *list, int PBN); // erase Block(after search(Block)), num is block address