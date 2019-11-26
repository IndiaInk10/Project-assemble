#include "func.h"

void menu(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30"); // cols=칸/행(가로) lines=줄/열(세로)

	int num = 0;
	bool answer = false;

	while (answer != true) {
		
		printf("PhoneBook implemented with C Language\n\n다음 중 수행할 작업을 고르시오.\n\n1. 출력    2. 검색    3. 추가\n4. 삭제    5. 수정    6. 종료\n\n>> ");

		scanf_s("%d", &num);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (num) {
		case 1: printPhoneBook(DLL); answer = true; break; // 출력함수
		case 2: searchInfo(DLL); answer = true; break; // 검색함수
		case 3: insertInfo(DLL); answer = true; break; // 삽입함수
		case 4: deleteInfo(DLL); answer = true; break; // 삭제함수
		case 5: modifyInfo(DLL); answer = true; break; // 수정함수
		case 6: answer = true; return; // 종료

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}
	
}
void endOrMenu(DLINKEDLIST *DLL) { // 메뉴 or 종료
	int eNum = 0;
	bool eAnswer = false;

	while (eAnswer != true) {
		printf("========================================\n");
		printf("\n다음 중 수행할 작업을 고르시오.\n\n1. 메뉴 2. 종료\n\n>> ");

		scanf_s("%d", &eNum);

		while (getchar() != '\n'); 

		switch (eNum) {
		case 1: menu(DLL); eAnswer = true;  break;
		case 2: eAnswer = true;  return;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); break;
		}
	}
}

void printPhoneBook(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");
	
	printf("===============전화번호부===============\n");
	dlPrint(DLL, dlSort(DLL)); // 정렬된 배열의 주소를 받아 이중연결리스트의 노드의 갯수만큼 출력하는 함수

	endOrMenu(DLL);
}
void searchInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char searchData[50]; // 찾는 데이터 값을 받기 위한 변수

	printf("검색할 이름 또는 전화번호 또는 이메일 중 하나를 입력하시오.\n\n>> ");

	scanf_s("%s", searchData, sizeof(searchData));

	if (dlSearchData(DLL, searchData) != NULL) {
		printf("========================================\n");
		NODE *sNode = (NODE*)malloc(sizeof(NODE));
		sNode = dlSearchData(DLL, searchData);
		printf("<<검색된 연락처의 정보>>\n이름: %s || 전화번호: %s || 이메일: %s\n", sNode->n_name, sNode->n_phoneNum, sNode->n_email);
	}

	endOrMenu(DLL);
}
void insertInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	NODE *iNode = (NODE*)malloc(sizeof(NODE));

	printf("추가할 이름을 입력하시오.\n\n>> ");
	scanf_s("%s", iNode->n_name, sizeof(iNode->n_name));
	printf("추가할 전화번호를 입력하시오.\n\n>> ");
	scanf_s("%s", iNode->n_phoneNum, sizeof(iNode->n_phoneNum));
	printf("추가할 이메일을 입력하시오.\n\n>> ");
	scanf_s("%s", iNode->n_email, sizeof(iNode->n_email));
	
	dlInsertLast(DLL, iNode);

	endOrMenu(DLL);
}
void modifyInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char mSearchData[50];	

	printf("수정할 이름 또는 전화번호 또는 이메일 중 하나를 입력하시오.\n\n>> ");

	scanf_s("%s", mSearchData, sizeof(mSearchData));

	if (dlSearchData(DLL, mSearchData) != NULL) {
		printf("========================================\n");
		NODE *mNode = (NODE*)malloc(sizeof(NODE));
		mNode = dlSearchData(DLL, mSearchData);
		printf("<<수정할 연락처의 정보>>\n이름: %s || 전화번호: %s || 이메일: %s\n", mNode->n_name, mNode->n_phoneNum, mNode->n_email);
		printf("========================================\n");

		printf("바꿀 이름을 입력하시오.\n\n>> ");
		scanf_s("%s", mNode->n_name, sizeof(mNode->n_name));
		printf("바꿀 전화번호를 입력하시오.\n\n>> ");
		scanf_s("%s", mNode->n_phoneNum, sizeof(mNode->n_phoneNum));
		printf("바꿀 이메일을 입력하시오.\n\n>> ");
		scanf_s("%s", mNode->n_email, sizeof(mNode->n_email));

		printf("해당 자료로 연락처가 수정되었습니다.\n");
	}

	endOrMenu(DLL);
}
void deleteInfo(DLINKEDLIST *DLL) {
	system("mode con cols=40 lines=30");

	char dSearchData[50];

	printf("삭제할 이름 또는 전화번호 또는 이메일 중 하나를 입력하시오.\n\n>> ");

	scanf_s("%s", dSearchData, sizeof(dSearchData));
	if (dlSearchData(DLL, dSearchData) != NULL) {
		printf("========================================\n");
		NODE *dNode = (NODE*)malloc(sizeof(NODE));
		dNode = dlSearchData(DLL, dSearchData);
		printf("<<삭제할 연락처의 정보>>\n이름: %s || 전화번호: %s || 이메일: %s\n", dNode->n_name, dNode->n_phoneNum, dNode->n_email);

		dlDelete(DLL, dNode);
	}
	
	endOrMenu(DLL);
}