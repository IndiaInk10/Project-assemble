#pragma once
#include <stdio.h> // �⺻ �Լ��� 
#include <stdlib.h> // �����޸� ������ ���� �Լ��� malloc, free
#include <stdbool.h> // bool�ڷ����� ����ϱ� ���� �������
#include <string.h> // strcmp�Լ��� ����ϱ� ���� �������
#include <Windows.h>

#include "dataStruct.h"
#include "DateCalFunc.h"

typedef struct node { // ����� ����ü
	struct node *llink;
	struct node *rlink;

	subs_or_videos sOrV;
}NODE;

typedef struct dLinkedList { // ���߿��Ḯ��Ʈ�� ���� �� ������ ���� ����ü
	NODE *head;
	NODE *tail;

	int count;
}DLINKEDLIST;

typedef struct sortArray { // ��������� ���� ����ü
	char name[SRENTNAME_SIZE];
	int count;

	NODE* data;
}SA;

NODE* createSNode(); // sube�����͸� ���� ��尪 �ʱ�ȭ
NODE* createVNode(); // video�����͸� ���� ��尪 �ʱ�ȭ

void dlSInit(DLINKEDLIST *list); // ���߿��Ḯ��Ʈ �ʱ�ȭ
void dlVInit(DLINKEDLIST *list);

bool dlIsEmpty(DLINKEDLIST *list); // ���߿��Ḯ��Ʈ�� ����ִ°�
int dlCount(DLINKEDLIST *list); // dlCount count���� �����ϴ� �Լ�
SA *dlSort(DLINKEDLIST *list); // ��������� �ϱ� ���� �Լ� - �ٲ�� �� ����

void dlInputFile(DLINKEDLIST *list, char *fileName); // ���߿��Ḯ��Ʈ�� ���� �Է�
void dlOutputFile(DLINKEDLIST *list, char *fileName); // ���߿��Ḯ��Ʈ�� ���� ���Ϸ� ���
void dlPrint(SA *Array); // ���߿��Ḯ��Ʈ�� ����ϴ� �Լ�
void dlSearchData(DLINKEDLIST *list, char *dataName, char *data); // �˻��� �Ͽ� ����� �ּҰ��� ��ȯ�ϴ� �Լ�
SA* dlModifyData(DLINKEDLIST *list, char *dataName, char *data);
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode); // ���߿��Ḯ��Ʈ�� �Էµ� �ڷᰡ �ִ� ��带 ��ũ�ϴ� �Լ�
void dlDelete(DLINKEDLIST *list, NODE *search); // �Էµ� ����� �ּҰ��� ��ũ�� Ǯ�� �޸������ϴ� �Լ�