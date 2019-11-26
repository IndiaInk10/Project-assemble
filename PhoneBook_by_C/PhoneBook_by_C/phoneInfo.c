#include "phoneInfo.h"

void dlInit(DLINKEDLIST *list) { // 이중연결리스트 초기화
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
	list->head->rlink = list->head->llink = NULL;
	list->tail->rlink = list->tail->llink = NULL;
	list->count = 0;
}
bool dlIsEmpty(DLINKEDLIST *list) { // 비어있느냐 원형이중연결리스트가 아니기 때문에 링크의 핵심은 head->rlink와 tail->llink + count는 추가 삭제시 +-가 이루어짐
	if (list->head->rlink == NULL && list->tail->llink == NULL && list->count == 0)
		return true;
	else
		return false;
}
int dlCount(DLINKEDLIST *list) { // 혹시나 이중연결리스트의 노드의 갯수를 알기 위한 함수
	return list->count;
}
SA *dlSort(DLINKEDLIST *list) { // 포인터 배열을 생성해 배열로 버블소팅을 하고 해당 배열의 주소값을 반환
	int dCount = dlCount(list);

	SA *sArray = (SA*)malloc(sizeof(SA)*dCount); // 동적할당을 이중연결리스트의 노드의 갯수만큼
	SA temp; // 버블소팅시 데이터를 이동시키기 위한 변수
	temp.sData = (NODE*)malloc(sizeof(NODE)); // 할당이 안되어있기 때문에 동적할당
	NODE *sort = (NODE*)malloc(sizeof(NODE)); // 이중연결리스트를 탐색하기 위한 sort노드
	sort = list->head->rlink;
	for (int i = 0; i < dCount; i++) // 이중연결리스트를 처음부터 끝까지 가면서 해당 데이터를 저장
	{
		strcpy_s(sArray[i].name, sizeof(sArray[i].name), sort->n_name); //이름으로 우선순위를 비교하기때문에 이름을 배열안의 이름데이터에 복사함
		sArray[i].sData = (NODE*)malloc(sizeof(NODE));
		sArray[i].sData = sort; // 그리고 이름에 맞는 노드의 주소값을 저장해놓음
		sort = sort->rlink;
	}
	sort = NULL; // 검색의 사용한 노드 메모리 해제
	free(sort);

	for (int j = 0; j < dCount - 1; j++) {
		for (int k = 0; k < dCount - 1; k++) {
			if (strcmp(sArray[k].name, sArray[k + 1].name) > 0) { // 버블소팅을 통해 우선순위대로 나열함(앞의 것이 아스키코드값이 크다, 앞의 것이 우선순위가 낮다 뒤로)
				temp = sArray[k];
				sArray[k] = sArray[k + 1];
				sArray[k + 1] = temp;
			}
		}
	}

	return sArray; // 배열의 주소값 리턴
}

void dlPrint(DLINKEDLIST *list, SA *array) { // 버블소팅을 하고 나서 해당 배열의 주소값을 가져와 오름차순으로 출력
	int l;
	
	if (dlIsEmpty(list) == true)
		printf("전화번호부에 연락처가 존재하지 않습니다.\n");
	else {
		for (l = 0; l < list->count; l++) { // 출력
			if (l == 0)	{
				printf("\n");
			}
			printf("이름: %s || 전화번호: %s || 이메일: %s\n", array[l].sData->n_name, array[l].sData->n_phoneNum, array[l].sData->n_email);
		}
	}
}
NODE* dlSearchData(DLINKEDLIST *list, char *data) { // 데이터를 통해 노드를 탐색하고 찾을 경우 해당 노드의 주소값을 리턴
	if (dlIsEmpty(list) == true) {
		printf("전화번호부에 연락처가 존재하지 않습니다.\n");
		return NULL;
	}	
	else {
		NODE *search = (NODE*)malloc(sizeof(NODE)); // 검색된 노드의 주소를 저장할 search노드 동적할당
		bool searchEd = false; // 검색이 됐는지 안됐는지 확인하는 bool값
		search = list->head->rlink;
		while (search != list->tail) { // tail 전까지만 데이터 비교
			if (strcmp(data, search->n_name) == 0 || strcmp(data, search->n_phoneNum) == 0 || strcmp(data, search->n_email) == 0) { // 데이터 비교하여 같으면 
				searchEd = true; // 검색표시하고
				return search; // 해당 노드의 주소값 리턴
			}
			search = search->rlink;
		}
		if (searchEd == false) // 검색이 안됨
		{
			printf("해당 자료를 가진 연락처는 없습니다.\n");
			return NULL;
		}
	}
	return NULL;
}
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode) { // 데이터가 입력된 노드를 이중연결리스트에 뒤쪽으로 삽입
	if (dlIsEmpty(list) == true) { // 비어있을 경우
		list->head->rlink = dataNode; // head와
		dataNode->llink = list->head;
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode; // tail에 링크
		list->tail->rlink = list->head;
		list->head->llink = list->tail;
		
		list->count += 1;
		printf("입력한 연락처가 저장되었습니다.\n");
	}
	else
	{
		list->tail->llink->rlink = dataNode; // 앞부분
		dataNode->llink = list->tail->llink; //   연결
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode;

		list->count += 1;
		printf("입력한 연락처가 저장되었습니다.\n");
	}
}
void dlDelete(DLINKEDLIST *list, NODE *search) { // 입력된 노드의 주소값의 메모리 해제
	NODE *remove = (NODE*)malloc(sizeof(NODE)); 
	if (list->count == 1) { // 하나만 있을 경우, 원형 이중연결리스트가 아니기에 절단
		list->head->rlink = NULL;
		list->tail->llink = NULL;
		list->count -= 1;
	}
	else { // 다른 경우는 삭제된 노드의 앞 노드와 뒷 노드를 연결
		remove = search;
		remove->llink->rlink = remove->rlink;
		remove->rlink->llink = remove->llink;
		list->count -= 1;
	}

	free(remove);
	printf("해당 자료를 가진 연락처가 삭제되었습니다.\n");
}