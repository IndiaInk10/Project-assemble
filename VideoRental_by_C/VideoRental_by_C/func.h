#pragma once
#include "DoubleLinkedList.h"

void Menu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //�޴�
void rentMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // rent�޴�
void endMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // ����޴�

void insertData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // �߰�
void printCanRent(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //���
void searchData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); //�˻�
void rentVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // �뿩
void returnVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // �ݳ�
void modifyData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // ����
void deleteData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL); // ����