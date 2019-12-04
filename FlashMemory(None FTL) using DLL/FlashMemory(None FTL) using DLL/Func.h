#pragma once
#include "DoubleLinkedList.h"
// include <stdio.h>, <string.h>, <stdlib.h>

void getCommand(DLL *list); // get command

DLL* init(DLL *list, int size); // create num MB Flash Memory, num is MB
void Flash_read(DLL *FlashMemory, int PSN); // read page data, num is sector address
void Flash_write(DLL *FlashMemory, int PSN, char data); // write data at sector, num is sector address
void Flash_erase(DLL *FlashMemory, int PBN); // erase block, num is sector address