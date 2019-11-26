#include "func.h"

void menu(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30"); // cols=ĭ/��(����) lines=��/��(����)

	int num = 0;
	bool answer = false;

	while (answer != true) {
		
		printf("PhoneBook implemented with C Language\n\n���� �� ������ �۾��� ���ÿ�.\n\n1. ���    2. �˻�    3. �߰�\n4. ����    5. ����    6. ����\n\n>> ");

		scanf_s("%d", &num);

		while (getchar() != '\n'); // ���۸� ���

		switch (num) {
		case 1: printPhoneBook(DLL); answer = true; break; // ����Լ�
		case 2: searchInfo(DLL); answer = true; break; // �˻��Լ�
		case 3: insertInfo(DLL); answer = true; break; // �����Լ�
		case 4: deleteInfo(DLL); answer = true; break; // �����Լ�
		case 5: modifyInfo(DLL); answer = true; break; // �����Լ�
		case 6: answer = true; return; // ����

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}
	
}
void endOrMenu(DLINKEDLIST *DLL) { // �޴� or ����
	int eNum = 0;
	bool eAnswer = false;

	while (eAnswer != true) {
		printf("========================================\n");
		printf("\n���� �� ������ �۾��� ���ÿ�.\n\n1. �޴� 2. ����\n\n>> ");

		scanf_s("%d", &eNum);

		while (getchar() != '\n'); 

		switch (eNum) {
		case 1: menu(DLL); eAnswer = true;  break;
		case 2: eAnswer = true;  return;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); break;
		}
	}
}

void printPhoneBook(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");
	
	printf("===============��ȭ��ȣ��===============\n");
	dlPrint(DLL, dlSort(DLL)); // ���ĵ� �迭�� �ּҸ� �޾� ���߿��Ḯ��Ʈ�� ����� ������ŭ ����ϴ� �Լ�

	endOrMenu(DLL);
}
void searchInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char searchData[50]; // ã�� ������ ���� �ޱ� ���� ����

	printf("�˻��� �̸� �Ǵ� ��ȭ��ȣ �Ǵ� �̸��� �� �ϳ��� �Է��Ͻÿ�.\n\n>> ");

	scanf_s("%s", searchData, sizeof(searchData));

	if (dlSearchData(DLL, searchData) != NULL) {
		printf("========================================\n");
		NODE *sNode = (NODE*)malloc(sizeof(NODE));
		sNode = dlSearchData(DLL, searchData);
		printf("<<�˻��� ����ó�� ����>>\n�̸�: %s || ��ȭ��ȣ: %s || �̸���: %s\n", sNode->n_name, sNode->n_phoneNum, sNode->n_email);
	}

	endOrMenu(DLL);
}
void insertInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	NODE *iNode = (NODE*)malloc(sizeof(NODE));

	printf("�߰��� �̸��� �Է��Ͻÿ�.\n\n>> ");
	scanf_s("%s", iNode->n_name, sizeof(iNode->n_name));
	printf("�߰��� ��ȭ��ȣ�� �Է��Ͻÿ�.\n\n>> ");
	scanf_s("%s", iNode->n_phoneNum, sizeof(iNode->n_phoneNum));
	printf("�߰��� �̸����� �Է��Ͻÿ�.\n\n>> ");
	scanf_s("%s", iNode->n_email, sizeof(iNode->n_email));
	
	dlInsertLast(DLL, iNode);

	endOrMenu(DLL);
}
void modifyInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char mSearchData[50];	

	printf("������ �̸� �Ǵ� ��ȭ��ȣ �Ǵ� �̸��� �� �ϳ��� �Է��Ͻÿ�.\n\n>> ");

	scanf_s("%s", mSearchData, sizeof(mSearchData));

	if (dlSearchData(DLL, mSearchData) != NULL) {
		printf("========================================\n");
		NODE *mNode = (NODE*)malloc(sizeof(NODE));
		mNode = dlSearchData(DLL, mSearchData);
		printf("<<������ ����ó�� ����>>\n�̸�: %s || ��ȭ��ȣ: %s || �̸���: %s\n", mNode->n_name, mNode->n_phoneNum, mNode->n_email);
		printf("========================================\n");

		printf("�ٲ� �̸��� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", mNode->n_name, sizeof(mNode->n_name));
		printf("�ٲ� ��ȭ��ȣ�� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", mNode->n_phoneNum, sizeof(mNode->n_phoneNum));
		printf("�ٲ� �̸����� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", mNode->n_email, sizeof(mNode->n_email));

		printf("�ش� �ڷ�� ����ó�� �����Ǿ����ϴ�.\n");
	}

	endOrMenu(DLL);
}
void deleteInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char dSearchData[50];

	printf("������ �̸� �Ǵ� ��ȭ��ȣ �Ǵ� �̸��� �� �ϳ��� �Է��Ͻÿ�.\n\n>> ");

	scanf_s("%s", dSearchData, sizeof(dSearchData));
	if (dlSearchData(DLL, dSearchData) != NULL) {
		printf("========================================\n");
		NODE *dNode = (NODE*)malloc(sizeof(NODE));
		dNode = dlSearchData(DLL, dSearchData);
		printf("<<������ ����ó�� ����>>\n�̸�: %s || ��ȭ��ȣ: %s || �̸���: %s\n", dNode->n_name, dNode->n_phoneNum, dNode->n_email);

		dlDelete(DLL, dNode);
	}
	
	endOrMenu(DLL);
}