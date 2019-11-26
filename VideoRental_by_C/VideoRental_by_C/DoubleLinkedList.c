#include "DoubleLinkedList.h"

NODE *createSNode() { // 가입자 정보를 다루는 노드
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	subs *data = (subs*)malloc(sizeof(subs));
	memset(newNode, 0, sizeof(NODE));
	memset(&(data->s_rent), 0, sizeof(sRent));
	memset(data, 0, sizeof(subs));
	

	newNode->llink = newNode->rlink = NULL;
	newNode->sOrV.pSubs = data;

	return newNode;
}

NODE *createVNode() { // 비디오 정보를 다루는 노드
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	videos *data = (videos*)malloc(sizeof(videos));
	memset(newNode, 0, sizeof(NODE));
	memset(data, 0, sizeof(videos)); 

	newNode->llink = newNode->rlink = NULL;
	newNode->sOrV.pVideos = data;

	return newNode;	
}					
					
void dlSInit(DLINKEDLIST *list) { // 가입자 이중연결리스트 초기화
	list->head = createSNode();
	list->tail = createSNode();
	list->head->rlink = list->head->llink = NULL;
	list->tail->rlink = list->tail->llink = NULL;
	list->count = 0;
}
void dlVInit(DLINKEDLIST *list) { // 비디오 이중연결리스트 초기화
	list->head = createVNode();
	list->tail = createVNode();
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

void dlInputFile(DLINKEDLIST *list, char *fileName) { // 파일을 이중연결리스트에 입력
	if (strcmp(fileName, "Subs.txt") == 0)  //  처음에 인자로 파일명을 받아와서 비교 후 가입자 따로 비디오 따로 입력을 받는다.
	{

		FILE *sFin;
		fopen_s(&sFin, fileName, "rt");
		
		if(sFin == NULL) { // 파일이 존재하지 않을 때
			printf("Subs파일이 존재하지 않습니다...\n");
			fclose(sFin);
		}
		else // sFin != NULL 파일이 존재할 때 
		{
			fseek(sFin, 0, SEEK_END); // 파일 끝으로 가서

			printf("Subs파일 읽습니다...\n");
			if (ftell(sFin) == 0) { // 해당 파일의 길이를 보고 비어있으면 예외처리
				printf("Subs파일이 비어있습니다...\n");
				fclose(sFin);
			}
			else // 아니면 입력 시작
			{
				fseek(sFin, 0, SEEK_SET); // 다시 파일 처음으로 가서 

				char sBuffer[522];
				char *div = "|";
				char *context;
				char *tok[11];

				printf("Subs파일에서 가입자 정보 가져오는 중... \n");
				while (feof(sFin) == 0) // 파일이 끝이 아닐 동안
				{
					NODE *sNode = createSNode(); // 가입자 노드 생성
					int tok4Num = 0, count = 0;

					fgets(sBuffer, sizeof(sBuffer), sFin); // 버퍼를 기준으로 파일에서 한 줄을 읽고

					context = sBuffer;

					for (int i = 0; i < 11; i++)
					{
						tok[i] = strtok_s(context, div, &context); //  구분 문자를 통해  데이터를 잘라서 저장

						if (i == 4) // 기존 데이터 이상의 정보는 아래의 조건을 통해 판별하여 더 추출
						{
							tok4Num = atoi(tok[4]);

							if (tok4Num == 0) {
								break;
							}
						}
						else if (i >= 5)
						{
							if (tok4Num == 1)
							{
								if (count == 1) {
									break;
								}
								else {
									count++;
									continue;
								}
							}
							else if (tok4Num == 2) {
								if (count == 3) {
									break;
								}
								else {
									count++;
									continue;
								}
							}
							else if (tok4Num == 3) {
								if (count == 5) {
									break;
								}
								else {
									count++;
									continue;
								}
							}
						}
					}
					// 추출한 데이터 저장
					sNode->sOrV.pSubs->s_id = atoi(tok[0]);
					strcpy_s(sNode->sOrV.pSubs->s_name, NAME_SIZE, tok[1]);
					strcpy_s(sNode->sOrV.pSubs->s_phone, PHONE_SIZE, tok[2]);
					strcpy_s(sNode->sOrV.pSubs->s_reside, RESIDE_SIZE, tok[3]);
					sNode->sOrV.pSubs->s_rent.sRentNum = tok4Num;
					if (count >= 1)
					{
						strcpy_s(&(sNode->sOrV.pSubs->s_rent.sRentName[0][0]), SRENTNAME_SIZE, tok[5]);
						strcpy_s(&(sNode->sOrV.pSubs->s_rent.SRNday[0][0]), SRNDAY_SIZE, tok[6]);
						if (count >= 3)
						{
							strcpy_s(&(sNode->sOrV.pSubs->s_rent.sRentName[1][0]), SRENTNAME_SIZE, tok[7]);
							strcpy_s(&(sNode->sOrV.pSubs->s_rent.SRNday[1][0]), SRNDAY_SIZE, tok[8]);
							if (count >= 5) {
								strcpy_s(&(sNode->sOrV.pSubs->s_rent.sRentName[2][0]), SRENTNAME_SIZE, tok[9]);
								strcpy_s(&(sNode->sOrV.pSubs->s_rent.SRNday[2][0]), SRNDAY_SIZE, tok[10]);
							}
						}
					}

					dlInsertLast(list, sNode); // 노드 삽입
				}

				fclose(sFin);
			}
		}
	}
	else if (strcmp(fileName, "Videos.txt") == 0) 
	{
		FILE *vFin;
		fopen_s(&vFin, fileName, "rt");
		
		if(vFin == NULL) { // 파일이 존재하지 않을 때
			printf("Videos파일이 존재하지 않습니다...\n");
			fclose(vFin);
		}
		else // vfin != NULL 파일이 존재할 때
		{
			fseek(vFin, 0, SEEK_END); // 파일 끝으로 감

			printf("Videos파일 읽습니다...\n");
			
			if (ftell(vFin) == 0) { // 길이가 0이면 파일이 비어있음
				printf("Videos파일이 비어있습니다...\n");
				fclose(vFin);
			}
			else 
			{
				fseek(vFin, 0, SEEK_SET); // 다시 파일의 처음으로 감

				char vBuffer[264];
				char *div = "|";
				char *context;
				char *tok[6];

				printf("비디오 목록 가져오는 중...\n");
				while (feof(vFin) == 0)
				{
					NODE *vNode = createVNode();

					fgets(vBuffer, sizeof(vBuffer), vFin);

					context = vBuffer;

					for (int i = 0; i < 6; i++) {
						tok[i] = strtok_s(context, div, &context);
					}

					strcpy_s(vNode->sOrV.pVideos->v_genre, GENRE_SIZE, tok[0]);
					strcpy_s(vNode->sOrV.pVideos->v_name, SRENTNAME_SIZE, tok[1]);
					strcpy_s(vNode->sOrV.pVideos->v_author, NAME_SIZE, tok[2]);
					strcpy_s(vNode->sOrV.pVideos->VRLday, SRNDAY_SIZE, tok[3]);
					vNode->sOrV.pVideos->v_num = atoi(tok[4]);
					vNode->sOrV.pVideos->v_rentNum = atoi(tok[5]);

					dlInsertLast(list, vNode);
				}

				fclose(vFin);
			}			
		}
		
	}
}
void dlOutputFile(DLINKEDLIST *list, char *fileName) {
	if (strcmp(fileName, "Subs.txt") == 0)
	{
		FILE *sFout;
		fopen_s(&sFout, fileName, "wt");

		if (sFout == NULL) { // 파일이 존재하지 않을 때
			printf("파일이 존재하지 않아 새로 생성하여 저장합니다...\n");
		}
		else // sFin != NULL 파일이 존재할 때 
		{
			printf("기존 파일을 제거하고 새로 생성하여 저장합니다...\n");
		}

		NODE *sSave = createSNode(); // 저장 및 탐색할 노드 생성

		for (sSave = list->head->rlink; sSave != list->tail; sSave = sSave->rlink)
		{
			char numBuffer[7];
			
			// int형 데이터가 있으면 문자열 데이터로 바꾸어 출력 하고 나머지 문자열 데이터들은 그냥 출력
			_itoa_s(sSave->sOrV.pSubs->s_id, numBuffer, _countof(numBuffer), 10);
			fputs(numBuffer, sFout); fputc('|', sFout);

			fputs(sSave->sOrV.pSubs->s_name, sFout); fputc('|', sFout);
			fputs(sSave->sOrV.pSubs->s_phone, sFout); fputc('|', sFout);
			fputs(sSave->sOrV.pSubs->s_reside, sFout); fputc('|', sFout);

			_itoa_s(sSave->sOrV.pSubs->s_rent.sRentNum, numBuffer, _countof(numBuffer), 10);
			fputs(numBuffer, sFout); fputc('|', sFout);
			
			for (int i = 0; i < 3; i++)
			{
				if (strlen(&(sSave->sOrV.pSubs->s_rent.sRentName[i][0])) != 0)
				// 해당 문자열이 비어 있지 않으면 출력(파일에 저장)
				{
					fputs(&(sSave->sOrV.pSubs->s_rent.sRentName[i][0]), sFout); fputc('|', sFout);
					fputs(&(sSave->sOrV.pSubs->s_rent.SRNday[i][0]), sFout); fputc('|', sFout);
				}
			}

			if(sSave != list->tail->llink)
				fputc('\n', sFout);
		}

		fclose(sFout);
	}
	else if (strcmp(fileName, "Videos.txt") == 0)
	{
		FILE *vFout;
		fopen_s(&vFout, fileName, "wt");

		if (vFout == NULL) { // 파일이 존재하지 않을 때
			printf("파일이 존재하지 않아 새로 생성하여 저장합니다...\n");
		}
		else // sfin != NULL 파일이 존재할 때 
		{
			printf("기존 파일을 제거하고 새로 생성하여 저장합니다...\n");
		}

		NODE *vSave = createVNode();

		for (vSave = list->head->rlink; vSave != list->tail; vSave = vSave->rlink)
		{
			char numBuffer[7];

			fputs(vSave->sOrV.pVideos->v_genre, vFout); fputc('|', vFout);
			fputs(vSave->sOrV.pVideos->v_name, vFout); fputc('|', vFout);
			fputs(vSave->sOrV.pVideos->v_author, vFout); fputc('|', vFout);
			fputs(vSave->sOrV.pVideos->VRLday, vFout); fputc('|', vFout);

			_itoa_s(vSave->sOrV.pVideos->v_num, numBuffer, _countof(numBuffer), 10);
			fputs(numBuffer, vFout); fputc('|', vFout);
			_itoa_s(vSave->sOrV.pVideos->v_rentNum, numBuffer, _countof(numBuffer), 10);
			fputs(numBuffer, vFout); fputc('|', vFout);

			if (vSave != list->tail->llink)
				fputc('\n', vFout);
		}

		fclose(vFout);
	}
}

SA *dlSort(DLINKEDLIST *list) { // 포인터 배열을 생성해 배열로 버블소팅을 하고 해당 배열의 주소값을 반환
	int dCount = dlCount(list);

	if (dCount == 0)
		printf("대여가능한 비디오가 없습니다.\n");
	else 
	{
		int rentableNum = 0;

		SA *sArray = (SA*)malloc(sizeof(SA)*dCount); // 동적할당을 이중연결리스트의 노드의 갯수만큼
		memset(sArray, 0, sizeof(SA)*dCount);
		SA temp = { 0, }; // 버블소팅시 데이터를 이동시키기 위한 변수
		temp.data = (NODE*)malloc(sizeof(NODE)); // 할당이 안되어있기 때문에 동적할당
		NODE *sort = createVNode(); // 이중연결리스트를 탐색하기 위한 sort노드
		sort = list->head->rlink;

		for (sort = list->head->rlink; sort != list->tail; sort = sort->rlink) // 이중연결리스트를 처음부터 끝까지 가면서 해당 데이터를 저장
		{
			if (((sort->sOrV.pVideos->v_num) - (sort->sOrV.pVideos->v_rentNum)) > 0) {
				printf("대여가능한 비디오 저장중...\n");
				strcpy_s(sArray[rentableNum].name, SRENTNAME_SIZE, sort->sOrV.pVideos->v_name); //이름으로 우선순위를 비교하기때문에 이름을 배열안의 이름데이터에 복사함
				sArray[rentableNum].data = (NODE*)malloc(sizeof(NODE));
				memset(sArray[rentableNum].data, 0, sizeof(NODE));
				sArray[rentableNum++].data = sort; // 그리고 이름에 맞는 데이터의 주소값을 저장해놓음
			}
			else {
				printf("넘어가는 중...\n");
			}
		}
		sort = NULL; // 검색의 사용한 노드 메모리 해제
		free(sort);

		for (int j = 0; j < rentableNum - 2; j++)
		{
			for (int k = 0; k < rentableNum - 2; k++)
			{
				if (strcmp(sArray[k + 1].name, "") == 0) {
					break;
				}
				else if (strcmp(sArray[k].name, sArray[k + 1].name) > 0) { // 버블소팅을 통해 우선순위대로 나열함(앞의 것이 아스키코드값이 크다, 앞의 것이 우선순위가 낮다 뒤로)
					temp = sArray[k];
					sArray[k] = sArray[k + 1];
					sArray[k + 1] = temp;
				}
			}
		}
		sArray[0].count = rentableNum;

		return sArray; // 배열의 주소값 리턴
	}
	
	return NULL;
}

void dlPrint(SA *array) { // 버블소팅을 하고 나서 해당 배열의 주소값을 가져와 오름차순으로 출력
	if (array == 0)
		return;
	else 
	{
		for (int l = 0; l < array[0].count; l++) 
		{ // 출력
			if (l == 0)	{
				printf("\n");
			}
			printf("장르: %s || 비디오 이름: %s || 감독: %s || 개봉일: %s\n", array[l].data->sOrV.pVideos->v_genre, array[l].data->sOrV.pVideos->v_name, array[l].data->sOrV.pVideos->v_author, array[l].data->sOrV.pVideos->VRLday);
		}
	}
	//free(array);
}

void dlSearchData(DLINKEDLIST *list, char* dataName, char *data) { 
	if (strcmp(dataName, "Subs") == 0) 
	{
		if (dlIsEmpty(list) == true) {
			printf("가입자 정보가 존재하지 않습니다.\n");
		}
		else {
			NODE *search = createSNode(); // 탐색할 노드 생성
			bool searchEd = false; // 검색이 됐는지 안됐는지 확인하는 bool값
			search = list->head->rlink;

			while (search != list->tail) { // tail 전까지만 데이터 비교
				if (strcmp(data, search->sOrV.pSubs->s_name) == 0 || strcmp(data, search->sOrV.pSubs->s_phone) == 0 || strcmp(data, search->sOrV.pSubs->s_reside) == 0) {// 데이터 비교하여 같으면 
					searchEd = true; // 검색표시하고
					printf("ID: %d || 이름: %s || 전화번호: %s || 거주지: %s || ", search->sOrV.pSubs->s_id, search->sOrV.pSubs->s_name, search->sOrV.pSubs->s_phone, search->sOrV.pSubs->s_reside);
					if (search->sOrV.pSubs->s_rent.sRentNum == 0) 
					{
						printf("대여한 비디오가 없습니다.\n");
					}
					else if (search->sOrV.pSubs->s_rent.sRentNum > 0)
					{
						printf("대여한 비디오 목록: %s", &(search->sOrV.pSubs->s_rent.sRentName[0][0]));
						if (search->sOrV.pSubs->s_rent.sRentNum > 1)
						{
							printf(", %s", &(search->sOrV.pSubs->s_rent.sRentName[1][0]));
							if(search->sOrV.pSubs->s_rent.sRentNum > 2)
								printf(", %s", &(search->sOrV.pSubs->s_rent.sRentName[2][0]));
						}
						printf("\n");
					}
				}
				search = search->rlink;
			}
			if (searchEd == false) // 검색이 안됨
			{
				printf("해당 자료를 가진 가입자는 없습니다.\n");
			}
		}
	}
	else if (strcmp(dataName, "Videos") == 0)
	{
		if (dlIsEmpty(list) == true) {
			printf("비디오 정보가 존재하지 않습니다.\n");
		}
		else {
			NODE *search = createSNode(); // 탐색할 노드 생성
			bool searchEd = false; // 검색이 됐는지 안됐는지 확인하는 bool값
			search = list->head->rlink;

			while (search != list->tail) { // tail 전까지만 데이터 비교
				if (strcmp(data, search->sOrV.pVideos->v_genre) == 0 || strcmp(data, search->sOrV.pVideos->v_name) == 0 || strcmp(data, search->sOrV.pVideos->v_author) == 0) { // 데이터 비교하여 같으면 
					searchEd = true; // 검색표시하고
					printf("장르: %s || 비디오 이름: %s || 감독: %s || 개봉일: %s || ", search->sOrV.pVideos->v_genre, search->sOrV.pVideos->v_name, search->sOrV.pVideos->v_author, search->sOrV.pVideos->VRLday);
					if (((search->sOrV.pVideos->v_num) - (search->sOrV.pVideos->v_rentNum)) == 0)
					{
						printf("대여 가능한 비디오 재고가 없습니다.\n");
					}
					else
					{
						printf("비디오 재고: %d\n", ((search->sOrV.pVideos->v_num) - (search->sOrV.pVideos->v_rentNum)));
					}
				}
				search = search->rlink;
			}
			if (searchEd == false) // 검색이 안됨
			{
				printf("해당 자료를 가진 비디오는 없습니다.\n");
			}
		}
	}
	else {
		printf("그런 이름의 정보는 없습니다.\n");
	}
}
SA* dlModifyData(DLINKEDLIST *list, char* dataName, char *data) { // 데이터를 통해 노드를 탐색하고 찾을 경우 해당 노드의 주소값을 리턴
	if (strcmp(dataName, "Subs") == 0)
	{
		if (dlIsEmpty(list) == true) {
			//printf("가입자 정보가 존재하지 않습니다.\n");
			return NULL;
		}
		else {
			int sSearchNum = 0;
			NODE *sSearch = createSNode(); // 검색된 노드의 주소를 저장할 search노드 동적할당
			SA *sSearchEdNode = (SA*)malloc(sizeof(SA)*dlCount(list)); // 노드의 주소값을 받는 노드의 주소값을 동적할당
			memset(sSearchEdNode, 0, sizeof(SA)*dlCount(list));

			bool sSearchEd = false; // 검색이 됐는지 안됐는지 확인하는 bool값
			sSearch = list->head->rlink;
			while (sSearch != list->tail) { // tail 전까지만 데이터 비교
				if (strcmp(data, sSearch->sOrV.pSubs->s_name) == 0 || strcmp(data, sSearch->sOrV.pSubs->s_phone) == 0 || strcmp(data, sSearch->sOrV.pSubs->s_reside) == 0) {// 데이터 비교하여 같으면
					sSearchEd = true; // 검색표시하고
					sSearchEdNode[sSearchNum++].data = sSearch; // 해당 자료를 가진 노드의 주소값 리턴
				}
				sSearch = sSearch->rlink;
			}
			sSearch = NULL; // 검색의 사용한 노드 메모리 해제
			free(sSearch);
			
			if (sSearchEd == true)
			{
				sSearchEdNode[0].count = sSearchNum;
				return sSearchEdNode;
			}
			else // 검색이 안됨
			{
				//printf("해당 자료를 가진 가입자는 없습니다.\n");
				return NULL;
			}
		}
	}
	else if (strcmp(dataName, "Videos") == 0)
	{
		if (dlIsEmpty(list) == true) {
			printf("비디오 정보가 존재하지 않습니다.\n");
			return NULL;
		}
		else {
			int vSearchNum = 0;
			NODE *vSearch = createSNode(); // 검색된 노드의 주소를 저장할 search노드 동적할당
			SA *vSearchEdNode = (SA*)malloc(sizeof(SA)*dlCount(list)); // 노드의 주소값을 받는 노드의 주소값을 동적할당
			memset(vSearchEdNode, 0, sizeof(SA)*dlCount(list));

			bool vSearchEd = false; // 검색이 됐는지 안됐는지 확인하는 bool값
			vSearch = list->head->rlink;
			while (vSearch != list->tail) { // tail 전까지만 데이터 비교
				if (strcmp(data, vSearch->sOrV.pVideos->v_genre) == 0 || strcmp(data, vSearch->sOrV.pVideos->v_name) == 0 || strcmp(data, vSearch->sOrV.pVideos->v_author) == 0) { // 데이터 비교하여 같으면 
					vSearchEd = true; // 검색표시하고
					vSearchEdNode[vSearchNum++].data = vSearch;
				}
				vSearch = vSearch->rlink;
			}
			vSearch = NULL; // 검색의 사용한 노드 메모리 해제
			free(vSearch);

			if (vSearchEd == true)
			{
				vSearchEdNode[0].count = vSearchNum;
				return vSearchEdNode;
			}
			else // 검색이 안됨
			{
				printf("해당 자료를 가진 비디오는 없습니다.\n");
				return NULL;
			}
		}
	}
	else {
		printf("그런 이름의 정보는 없습니다.\n");
		return NULL;
	}

	return NULL;
}

void dlInsertLast(DLINKEDLIST *list, NODE *dataNode) { // 데이터가 입력된 노드를 이중연결리스트에 뒤쪽으로 삽입
	if (dlIsEmpty(list) == true) { // 비어있을 경우
		list->head->rlink = dataNode; // head와
		dataNode->llink = list->head;
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode; // tail에 링크

		list->count += 1;
		printf("입력한 첫 정보가 저장되었습니다.\n");
	}
	else
	{
		list->tail->llink->rlink = dataNode; // 앞부분
		dataNode->llink = list->tail->llink; //   연결
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode;

		list->count += 1;
		printf("입력한 정보가 저장되었습니다.\n");
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
	printf("해당 자료를 가진 정보가 삭제되었습니다.\n");
}