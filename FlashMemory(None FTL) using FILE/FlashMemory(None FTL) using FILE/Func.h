#pragma once
#include "File.h"

void getCommand(FILE *file); // get command

void init(FILE *file, int size); // create num MB Flash Memory, num is MB
void Flash_read(FILE *FlashMemory, int PSN); // read page data, num is sector address
void Flash_write(FILE *FlashMemory, int PSN, char data); // write data at sector, num is sector address
void Flash_erase(FILE *FlashMemory, int PBN); // erase block, num is sector address