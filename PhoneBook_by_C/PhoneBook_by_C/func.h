#pragma once // #ifndef __��������̸�(�빮��)_H_ #endif
#include <stdio.h>
#include <windows.h> // â������ �����ǰ� �ϴ� �������
#include "phoneInfo.h" // ���߿��Ḯ��Ʈ �����ϱ� ���� �Լ�

void menu(DLINKEDLIST *DLL); //�޴�
void endOrMenu(DLINKEDLIST *DLL); // ����

void printPhoneBook(DLINKEDLIST *DLL); //���
void searchInfo(DLINKEDLIST *DLL); //�˻�
void insertInfo(DLINKEDLIST *DLL); // �߰�
void modifyInfo(DLINKEDLIST *DLL); // ����
void deleteInfo(DLINKEDLIST *DLL); // ����