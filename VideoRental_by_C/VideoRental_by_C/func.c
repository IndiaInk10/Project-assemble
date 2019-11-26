#include "func.h"

void Menu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30"); // cols=칸/행(가로) lines=줄/열(세로)

	int num = 0;
	bool answer = false;

	while (answer != true) 
	{
		printf("VideoRental implemented with C Language\n\n다음 중 수행할 작업을 고르시오.\n");
		printf("1. 추가(가입자, 비디오)    2. 출력(대여 가능한 비디오)    3. 검색(가입자, 비디오)\n");
		printf("4. 비디오 대여    5. 비디오 반납    6. 수정(가입자, 비디오)    7. 삭제(가입자, 비디오)    8. 종료\n");
		printf(">> ");

		scanf_s("%d", &num);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (num) {
		case 1: insertData(sDLL, vDLL); answer = true; break;
		case 2: printCanRent(sDLL, vDLL); answer = true; break;
		case 3: searchData(sDLL, vDLL); answer = true; break;
		case 4: rentVideo(sDLL, vDLL); answer = true; break;
		case 5: returnVideo(sDLL, vDLL); answer = true; break;
		case 6: modifyData(sDLL, vDLL); answer = true; break;
		case 7: deleteData(sDLL, vDLL); answer = true; break;
		case 8: answer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}
}
void rentMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	int rNum = 0;
	bool rAnswer = false;

	while (rAnswer != true)
	{
		printf("다음 중 수행할 작업을 고르시오.\n");
		printf("1. 비디오 대여    2. 비디오 반납    3. 메뉴    4. 종료\n");
		printf(">> ");

		scanf_s("%d", &rNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (rNum) {
		case 1: rentVideo(sDLL, vDLL); rAnswer = true; break;
		case 2: returnVideo(sDLL, vDLL); rAnswer = true; break;
		case 3: Menu(sDLL, vDLL); rAnswer = true; break;
		case 4: rAnswer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}
}
void endMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	int eNum = 0;
	bool eAnswer = false;

	while (eAnswer != true)
	{
		printf("다음 중 수행할 작업을 고르시오.\n");
		printf("1. 메뉴    2. 종료\n");
		printf(">> ");

		scanf_s("%d", &eNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (eNum) {
		case 1: Menu(sDLL, vDLL); eAnswer = true; break;
		case 2: eAnswer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}
}

void insertData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	int iNum = 0;
	bool iAnswer = false;

	while(iAnswer != true) {
		printf("입력할 정보를 고르시오.\n");
		printf("1. 가입자    2.비디오.\n");
		printf(">>");

		scanf_s("%d", &iNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (iNum) {
		case 1: iAnswer = true; break;
		case 2: iAnswer = true; break;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}

	if (iNum == 1) {
		NODE *ISNode = createSNode();

		if (dlIsEmpty(sDLL) == true)
			ISNode->sOrV.pSubs->s_id = 0;
		else
			ISNode->sOrV.pSubs->s_id = sDLL->tail->llink->sOrV.pSubs->s_id + 1; // 맨 뒤에 있는 사람 id + 1

		printf("가입자의 이름을 입력하시오.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_name, NAME_SIZE);
		printf("가입자의 전화번호를 입력하시오.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_phone, PHONE_SIZE);
		printf("가입자의 거주지 입력하시오.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_reside, RESIDE_SIZE);

		dlInsertLast(sDLL, ISNode);

		dlOutputFile(sDLL, "Subs.txt");

		while (getchar() != '\n');

		rentMenu(sDLL, vDLL);
	}
	else {
		NODE *IVNode = createVNode();

		printf("비디오의 이름을 입력하시오.\n\n>> ");
		scanf_s("%s", IVNode->sOrV.pVideos->v_name, SRENTNAME_SIZE);
		if (dlModifyData(vDLL, "Videos", IVNode->sOrV.pVideos->v_name) != NULL) // 이미 있는 비디오 이름이 입력되면
		{
			SA *MVNode;
			int addNum = 0;

			MVNode = dlModifyData(vDLL, "Videos", IVNode->sOrV.pVideos->v_name);

			printf("해당 비디오는 이미 존재합니다.");
			while (1)
			{
				printf("추가되는 수량을 입력하시오.\n\n>> ");
				if (scanf_s("%d", &addNum) == 0)
				{
					printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

					while (getchar() != '\n');
				}
				else
				{
					if (addNum > 0)
					{
						MVNode[0].data->sOrV.pVideos->v_num += addNum;
						break;
					}
					else
					{
						printf("0 보다 작은 수를 입력되었습니다. 다시 입력해주세요.\n");
					}
				}				
			}
			IVNode = NULL;
			free(IVNode);

			dlOutputFile(vDLL, "Videos.txt");

			endMenu(sDLL, vDLL);
		}
		else
		{
			printf("비디오의 장르를 입력하시오.\n\n>> ");
			scanf_s("%s", IVNode->sOrV.pVideos->v_genre, GENRE_SIZE);
			printf("비디오의 감독을 입력하시오.\n\n>> ");
			scanf_s("%s", IVNode->sOrV.pVideos->v_author, NAME_SIZE);
			while (strlen(IVNode->sOrV.pVideos->VRLday) != 10)
			{
				printf("개봉일을 입력하시오. ex) 0000-00-00\n\n>> ");
				scanf_s("%s", IVNode->sOrV.pVideos->VRLday, SRNDAY_SIZE);
				if (strlen(IVNode->sOrV.pVideos->VRLday) != 10)
				{
					printf("잘못된 입력입니다. 다시 입력해주세요.\n");
				}
			}
			while (1)
			{
				printf("비디오의 수량을 입력하시오.\n\n>> ");
				if (scanf_s("%d", &(IVNode->sOrV.pVideos->v_num)) == 0)
				{
					printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

					while (getchar() != '\n');
				}
				else
				{
					if (IVNode->sOrV.pVideos->v_num > 0)
					{
						break;
					}
					else
					{
						printf("0 보다 작은 수를 입력되었습니다. 다시 입력해주세요.\n");
					}
				}
			}
			
		}

		dlInsertLast(vDLL, IVNode);

		dlOutputFile(vDLL, "Videos.txt");

		endMenu(sDLL, vDLL);
	}
}
void printCanRent(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");

	printf("대여가능한 비디오 목록\n");
	dlPrint(dlSort(vDLL));

	rentMenu(sDLL, vDLL);
}
void searchData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	int sNum = 0;
	bool sAnswer = false;

	while (sAnswer != true) {
		printf("검색할 정보를 고르시오.\n");
		printf("1. 가입자    2.비디오.\n");
		printf(">>");

		scanf_s("%d", &sNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (sNum) {
		case 1: sAnswer = true; break;
		case 2: sAnswer = true; break;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}

	if (sNum == 1)
	{
		char search[NAME_SIZE]; // 제일 큰 데이터 값으로 선언

		printf("검색할 정보를 입력하시오. ex)이름 전화번호 거주지 등...\n\n>> ");
		scanf_s("%s", search, NAME_SIZE);

		dlSearchData(sDLL, "Subs", search);
	}
	else
	{
		char search[NAME_SIZE];

		printf("검색할 정보를 입력하시오. ex)장르 비디오명 감독 개봉일 등...\n\n>> ");
		scanf_s("%s", search, NAME_SIZE);

		dlSearchData(vDLL, "Videos", search);
	}

	rentMenu(sDLL, vDLL);
}
void rentVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	char RSearch[NAME_SIZE];
	int ID;
	SA *RSNode;

	while (1)
	{
		printf("대여할 가입자 정보를 입력하시오. ex)이름 전화번호 거주지 등...\n\n>> ");
		scanf_s("%s", RSearch, NAME_SIZE);
		RSNode = dlModifyData(sDLL, "Subs", RSearch);

		if (RSNode != NULL)
			break;
		else
		{
			printf("해당 정보를 가진 가입자는 없습니다. 다시 입력해주세요.\n");
		}
	}

	dlSearchData(sDLL, "Subs", RSearch);

	while (1)
	{
		printf("다음 중 자신의 ID를 입력하시오.\n\n>> ");

		if (scanf_s("%d", &ID) == 0)
		{
			printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");

			while (getchar() != '\n');
		}
		else
		{
			bool bID = false;

			for (int i = 0; i < RSNode[0].count; i++)
			{
				if (ID == RSNode[i].data->sOrV.pSubs->s_id)
				{
					bID = true;
					ID = i;
					break;
				}
			}

			if (bID == true)
			{
				break;
			}
			else
			{
				printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");
			}
		}
	}

	if (RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum == 3)
	{
		printf("%s님께서는 총 대여가능 횟수(3회)를 다 사용하셨기 때문에 더 이상 대여할 수 없습니다.\n", RSNode[ID].data->sOrV.pSubs->s_name);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			RSNode[j].data = NULL;
			free(RSNode[j].data);
		}
		free(RSNode);

		rentMenu(sDLL, vDLL);
	}

	//=======================================================================================//

	else
	{
		SA *RVNode;
		char rVRLdate[SRNDAY_SIZE];
		Date *rDate, *VRLDate;
		int addFee = 5000;

		printf("대여가능한 비디오 목록\n");						  // 빌릴수 있는 비디오 목록만 보여준 다음
		dlPrint(dlSort(vDLL));
		
		printf("다음 중 대여할 비디오의 이름을 입력하시오.\n\n>> ");	  // 빌릴 비디오의 이름을 적게 함
		scanf_s("%s", RSearch, NAME_SIZE);
		RVNode = dlModifyData(vDLL, "Videos", RSearch);

		strcpy_s(rVRLdate, SRNDAY_SIZE, RVNode[0].data->sOrV.pVideos->VRLday);
		VRLDate = changeInteger(rVRLdate);
		rDate = getDate(); // 현재 날짜를 받아오고

		if (VRLDate->y <= rDate->y - 16) // 최소 대여료는 2000원으로 설정
		{
			addFee = 2000;
		}
		else
		{
			addFee = addFee - (rDate->y / 3 - VRLDate->y / 3) * 500; // 현재 년도 아랫(-1)년도에 개봉한 비디오나 영화는 3년을 기준으로 -500 원
		}
		
		printf("해당 비디오의 대여료는 %d입니다.\n", addFee);

		for (int i = 0; i < 3; i++)
		{
			if (strlen(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0])) == 0)
			{
				strcpy_s(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0]), SRENTNAME_SIZE, RVNode[0].data->sOrV.pVideos->v_name);
				strcpy_s(&(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[i][0]), SRNDAY_SIZE, changeString(rDate->y, rDate->m, rDate->d));
				break;
			}
		}

		RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum += 1; // 가입자 대여 횟수 증가
		RVNode[0].data->sOrV.pVideos->v_rentNum += 1; // 비디오 대여된 횟수 증가

		free(rDate);
		free(VRLDate);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			RSNode[j].data = NULL;
			free(RSNode[j].data);
		}
		for (int k = 0; k < dlCount(vDLL); k++)
		{
			RVNode[k].data = NULL;
			free(RVNode[k].data);
		}
		free(RSNode);
		free(RVNode);

		dlOutputFile(sDLL, "Subs.txt");
		dlOutputFile(vDLL, "Videos.txt");

		Sleep(8000);

		Menu(sDLL, vDLL);
	}
}
void returnVideo(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	char RSearch[NAME_SIZE];
	int ID;
	SA *RSNode;

	while (1)
	{
		printf("반납할 가입자 정보를 입력하시오. ex)이름 전화번호 거주지 등...\n\n>> ");
		scanf_s("%s", RSearch, NAME_SIZE);
		RSNode = dlModifyData(sDLL, "Subs", RSearch);

		if (RSNode != NULL)
			break;
		else
		{
			printf("해당 정보를 가진 가입자는 없습니다. 다시 입력해주세요.\n");
		}
	}

	dlSearchData(sDLL, "Subs", RSearch);

	while (1)
	{
		printf("다음 중 자신의 ID를 입력하시오.\n\n>> ");

		if (scanf_s("%d", &ID) == 0)
		{
			printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");

			while (getchar() != '\n');
		}
		else
		{
			bool bID = false;

			for (int i = 0; i < RSNode[0].count; i++)
			{
				if (ID == RSNode[i].data->sOrV.pSubs->s_id)
				{
					bID = true;
					ID = i;
					break;
				}
			}

			if (bID == true)
			{
				break;
			}
			else
			{
				printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");
			}
		}
	}

	if (RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum == 0)
	{
		printf("%s님께서는 대여한 비디오가 없습니다.\n", RSNode[ID].data->sOrV.pSubs->s_name);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			RSNode[j].data = NULL;
			free(RSNode[j].data);
		}
		free(RSNode);

		rentMenu(sDLL, vDLL);
	}

	//=======================================================================================//

	else
	{
		char rVRLdate[SRNDAY_SIZE];
		SA *RVNode;
		Date *rDate, *rentDate = NULL;

		printf("%s님이 대여한 비디오 목록은 ", RSNode[ID].data->sOrV.pSubs->s_name);
		for (int i = 0; i < RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum; i++)
		{
			if (strlen(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0])) != 0)
			{
				printf("%s", &(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0]));
			}
			if (i + 1 != RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum)
			{
				printf(", ");
			}
		}
		printf("입니다.\n");

		printf("다음 중 반납할 비디오의 이름을 입력하시오.\n\n>> ");	  // 반납할 비디오의 이름을 적게 함
		scanf_s("%s", RSearch, SRENTNAME_SIZE);
		RVNode = dlModifyData(vDLL, "Videos", RSearch);

		for (int j = 0; j < RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum; j++)
		{
			if (strcmp(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[j][0]), RVNode[0].data->sOrV.pVideos->v_name) == 0)
			{
				strcpy_s(rVRLdate, SRNDAY_SIZE, &(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[j][0]));
				rentDate = changeInteger(rVRLdate);

				memset(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[j][0]), 0, SRENTNAME_SIZE); // 대여한 기록 삭제
				memset(&(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[j][0]), 0, SRNDAY_SIZE); // 대여한 기록 삭제
			}
		}

		rDate = getDate(); // 현재 날짜를 받아오고

		if (DateCal(*rDate, *rentDate) > 14)
		{
			printf("연체료는 %d원입니다.\n", (DateCal(*rDate, *rentDate) - 14) * 100); // 연체료는 일당 100원으로 계산 무자비
		}
		printf("반납되었습니다.\n");

		RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum -= 1; // 가입자 대여 횟수 감소
		RVNode[0].data->sOrV.pVideos->v_rentNum -= 1; // 비디오 대여된 횟수 감소

		free(rDate);
		free(rentDate);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			RSNode[j].data = NULL;
			free(RSNode[j].data);			
		}
		for (int k = 0; k < dlCount(vDLL); k++)
		{
			RVNode[k].data = NULL;
			free(RVNode[k].data);

		}
		free(RSNode);
		free(RVNode);

		dlOutputFile(sDLL, "Subs.txt");
		dlOutputFile(vDLL, "Videos.txt");

		Sleep(8000);

		Menu(sDLL, vDLL);
	}
}
void modifyData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");

	int mNum = 0;
	bool mAnswer = false;

	while (mAnswer != true) {
		printf("수정할 정보를 고르시오.\n");
		printf("1. 가입자    2.비디오.\n");
		printf(">>");

		scanf_s("%d", &mNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (mNum) {
		case 1: mAnswer = true; break;
		case 2: mAnswer = true; break;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}

	if (mNum == 1) {
		char MSearch[NAME_SIZE];
		int ID;
		SA *MSNode;

		while (1)
		{
			printf("수정할 가입자 정보를 입력하시오. ex)이름 전화번호 거주지 등...\n\n>> ");
			scanf_s("%s", MSearch, NAME_SIZE);
			MSNode = dlModifyData(sDLL, "Subs", MSearch);

			if (MSNode != NULL)
				break;
			else
			{
				printf("해당 정보를 가진 가입자는 없습니다. 다시 입력해주세요.\n");
			}
		}

		dlSearchData(sDLL, "Subs", MSearch);

		while (1)
		{
			printf("다음 중 자신의 ID를 입력하시오.\n\n>> ");

			if (scanf_s("%d", &ID) == 0)
			{
				printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");

				while (getchar() != '\n');
			}
			else
			{
				bool bID = false;

				for (int i = 0; i < MSNode[0].count; i++)
				{
					if (ID == MSNode[i].data->sOrV.pSubs->s_id)
					{
						bID = true;
						ID = i;
						break;
					}
				}

				if (bID == true)
				{
					break;
				}
				else
				{
					printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");
				}
			}
		}

		if (MSNode[ID].data->sOrV.pSubs->s_rent.sRentNum != 0)
		{
			printf("해당 가입자는 대여한 비디오가 있기 때문에 수정할 수 없습니다.\n");

			for (int j = 0; j < dlCount(sDLL); j++)
			{
				MSNode[j].data = NULL;
				free(MSNode[j].data);
			}
			free(MSNode);

			rentMenu(sDLL, vDLL);
		}

		printf("수정할 이름을 입력하시오.\n\n>> ");
		scanf_s("%s", MSNode[ID].data->sOrV.pSubs->s_name, NAME_SIZE);
		printf("수정할 전화번호를 입력하시오.\n\n>> ");
		scanf_s("%s", MSNode[ID].data->sOrV.pSubs->s_phone, PHONE_SIZE);
		printf("수정할 거주지 입력하시오.\n\n>> ");
		scanf_s("%s", MSNode[ID].data->sOrV.pSubs->s_reside, RESIDE_SIZE);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			MSNode[j].data = NULL;
			free(MSNode[j].data);
		}
		free(MSNode);

		dlOutputFile(sDLL, "Subs.txt");

		rentMenu(sDLL, vDLL);
	}
	else {
		char MSearch[NAME_SIZE];
		int modiNum;
		SA *MVNode;
		int VName;
		int MNameNum;

		while (1)
		{
			printf("수정할 비디오의 정보를 입력하시오. ex)장르 비디오명 감독 개봉일 등...\n\n>> ");
			scanf_s("%s", MSearch, NAME_SIZE);
			MVNode = dlModifyData(vDLL, "Videos", MSearch);

			if (MVNode != NULL)
				break;
			else
			{
				printf("해당 정보를 가진 비디오는 없습니다. 다시 입력해주세요.\n");
			}
		}

		dlSearchData(vDLL, "Videos", MSearch);

		while (1)
		{
			printf("다음 중 비디오 이름을 입력하시오.\n\n>> ");
			scanf_s("%s", MSearch, NAME_SIZE);

			bool bName = false;

			for (int i = 0; i < MVNode[0].count; i++)
			{
				if (strcmp(MVNode[i].data->sOrV.pVideos->v_name, MSearch) == 0)
				{
					VName = i;
					bName = true;
				}
			}

			if (bName == true)
				break;
			else
			{
				printf("잘못된 비디오 이름 입력입니다. 다시 입력해주세요.\n");
			}
		}

		if (MVNode[VName].data->sOrV.pVideos->v_rentNum != 0)
		{
			printf("해당 비디오는 대여한 가입자가 있기 때문에 수정할 수 없습니다.\n");

			for (int j = 0; j < dlCount(vDLL); j++)
			{
				MVNode[j].data = NULL;
				free(MVNode[j].data);
			}
			free(MVNode);

			Menu(sDLL, vDLL);
		}

		while (1)
		{
			printf("비디오 이름을 수정하시겠습니다?\n");
			printf("1. 예    2. 아니오\n\n>> ");
			if (scanf_s("%d", &MNameNum) == 0)
			{
				printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

				while (getchar() != '\n');
			}
			else if (MNameNum == 1)
			{
				printf("수정할 이름을 입력하시오.\n\n>> ");
				scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_name, SRENTNAME_SIZE);
				break;
			}
			else if (MNameNum == 2)
			{
				break;
			}
			else
			{
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			}
		}
		

		printf("수정할 장르를 입력하시오.\n\n>> ");
		scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_genre, GENRE_SIZE);
		printf("수정할 감독을 입력하시오.\n\n>> ");
		scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_author, NAME_SIZE);
		while (strlen(MVNode[VName].data->sOrV.pVideos->VRLday) != 10)
		{
			printf("수정할 개봉일을 입력하시오. ex) 0000-00-00\n\n>> ");
			scanf_s("%s", MVNode[VName].data->sOrV.pVideos->VRLday, SRNDAY_SIZE);
			if (strlen(MVNode[VName].data->sOrV.pVideos->VRLday) != 10)
			{
				printf("잘못된 입력입니다. 다시 입력해주세요.\n");
			}
		}
		if (MVNode[VName].data->sOrV.pVideos->v_num > 0 && MVNode[VName].data->sOrV.pVideos->v_rentNum == 0)
		{
			printf("수정할 수량을 입력하시오(최대 수정 가능한 수량: %d)\n\n>> ", MVNode[VName].data->sOrV.pVideos->v_num);
			while (1)
			{
				if (scanf_s("%d", &modiNum) == 0)
				{
					printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

					while (getchar() != '\n');
				}
				else
				{
					MVNode[VName].data->sOrV.pVideos->v_num = modiNum;
					break;
				}
			}
		}
		else
		{
			if ((MVNode[VName].data->sOrV.pVideos->v_num - MVNode[VName].data->sOrV.pVideos->v_rentNum) > 0)
			{
				printf("수정할 수량을 입력하시오(최대 수정 가능한 수량: %d 이상)\n\n>> ", MVNode[VName].data->sOrV.pVideos->v_rentNum);
				while (1)
				{
					if (scanf_s("%d", &modiNum) == 0)  // 대여된 비디오 수 보다 작은 수로 설정 불가능
					{
						printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

						while (getchar() != '\n');
					}
					else
					{
						if (modiNum >= MVNode[VName].data->sOrV.pVideos->v_rentNum)
						{
							MVNode[VName].data->sOrV.pVideos->v_num = modiNum;
							break;
						}
						else
							printf("최대 수정 가능한 수량보다 적습니다. 다시 입력해주세요.\n");
					}
				}
			}
			else
			{
				printf("해당 비디오는 모두 대여된 상태이기 때문에 수정할 수 없습니다.\n");
			}
		}

		for (int j = 0; j < dlCount(vDLL); j++)
		{
			MVNode[j].data = NULL;
			free(MVNode[j].data);
		}
		free(MVNode);

		dlOutputFile(vDLL, "Videos.txt");

		endMenu(sDLL, vDLL);
	}
}
void deleteData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");

	int dNum = 0;
	bool dAnswer = false;

	while (dAnswer != true) {
		printf("삭제할 정보를 고르시오.\n");
		printf("1. 가입자    2.비디오.\n");
		printf(">>");

		scanf_s("%d", &dNum);

		while (getchar() != '\n'); // 버퍼를 비움

		switch (dNum) {
		case 1: dAnswer = true; break;
		case 2: dAnswer = true; break;

		default: printf("========================================\n"); printf("그런 작업은 없습니다.\n"); printf("========================================\n"); break;
		}
	}

	if (dNum == 1) {
		char DSearch[NAME_SIZE];
		int ID;
		SA *DSNode;

		while (1)
		{
			printf("삭제할 가입자 정보를 입력하시오. ex)이름 전화번호 거주지 등...\n\n>> ");
			scanf_s("%s", DSearch, NAME_SIZE);
			DSNode = dlModifyData(sDLL, "Subs", DSearch);

			if (DSNode != NULL)
				break;
			else
			{
				printf("해당 정보를 가진 가입자는 없습니다. 다시 입력해주세요.\n");
			}
		}
		
		dlSearchData(sDLL, "Subs", DSearch);

		while (1)
		{
			printf("다음 중 자신의 ID를 입력하시오.\n\n>> ");

			if (scanf_s("%d", &ID) == 0)
			{
				printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");

				while (getchar() != '\n');
			}
			else
			{
				bool bID = false;

				for (int i = 0; i < DSNode[0].count; i++)
				{
					if (ID == DSNode[i].data->sOrV.pSubs->s_id)
					{
						bID = true;
						ID = i;
						break;
					}
				}

				if (bID == true)
				{
					break;
				}
				else
				{
					printf("잘못된 ID 입력입니다. 다시 입력해주세요.\n");
				}
			}
		}

		if (DSNode[ID].data->sOrV.pSubs->s_rent.sRentNum != 0)
		{
			printf("%s님께서는 대여한 비디오가 있기 때문에 정보를 삭제할 수 없습니다.\n", DSNode[ID].data->sOrV.pSubs->s_name);

			for (int j = 0; j < dlCount(sDLL); j++)
			{
				DSNode[j].data = NULL;
				free(DSNode[j].data);
			}
			free(DSNode);

			rentMenu(sDLL, vDLL);
		}

		dlDelete(sDLL, DSNode[ID].data);

		for (int j = 0; j < dlCount(sDLL); j++)
		{
			DSNode[j].data = NULL;
			free(DSNode[j].data);
		}
		free(DSNode);

		dlOutputFile(sDLL, "Subs.txt");

		Sleep(8000);

		Menu(sDLL, vDLL);
	}
	else {
		char DVSearch[NAME_SIZE];
		SA *DVNode;
		int VName;
		int delNum = 0;

		while (1)
		{
			printf("삭제할 비디오의 정보를 입력하시오. ex)장르 비디오명 감독 개봉일 등...\n\n>> ");
			scanf_s("%s", DVSearch, NAME_SIZE);
			DVNode = dlModifyData(vDLL, "Videos", DVSearch);

			if (DVNode != NULL)
				break;
			else
			{
				printf("해당 정보를 가진 비디오는 없습니다. 다시 입력해주세요.\n");
			}
		}

		dlSearchData(vDLL, "Videos", DVSearch);

		while (1)
		{
			printf("다음 중 비디오 이름을 입력하시오.\n\n>> ");
			scanf_s("%s", DVSearch, NAME_SIZE);
			
			bool bName = false;

			for (int i = 0; i < DVNode[0].count; i++)
			{
				if (strcmp(DVNode[i].data->sOrV.pVideos->v_name, DVSearch) == 0)
				{
					VName = i;
					bName = true;
				}
			}

			if (bName == true)
				break;
			else
			{
				printf("잘못된 비디오 이름 입력입니다. 다시 입력해주세요.\n");
			}
		}

		if (DVNode[VName].data->sOrV.pVideos->v_num > 0 && DVNode[VName].data->sOrV.pVideos->v_rentNum == 0)
		{
			printf("삭제할 수량을 입력하시오(최대 수정 가능한 수량: %d)\n\n>> ", DVNode[VName].data->sOrV.pVideos->v_num);
			while (1)
			{
				if (scanf_s("%d", &delNum) == 0)
				{
					printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

					while (getchar() != '\n');
				}
				else
				{
					DVNode[VName].data->sOrV.pVideos->v_num = DVNode[VName].data->sOrV.pVideos->v_num - delNum;
					break;
				}
			}
		}
		else
		{
			if ((DVNode[VName].data->sOrV.pVideos->v_num - DVNode[VName].data->sOrV.pVideos->v_rentNum) > 0)
			{
				printf("삭제할 수량을 입력하시오(최대 삭제 가능한 수량: %d 이하)\n\n>> ", DVNode[VName].data->sOrV.pVideos->v_num - DVNode[VName].data->sOrV.pVideos->v_rentNum);
				while (1)
				{
					if (scanf_s("%d", &delNum) == 0)  // 대여된 비디오 수 보다 작은 수로 설정 불가능
					{
						printf("문자가 입력되었습니다. 다시 입력해주세요.\n");

						while (getchar() != '\n');
					}
					else
					{
						if (delNum <= DVNode[VName].data->sOrV.pVideos->v_num - DVNode[VName].data->sOrV.pVideos->v_rentNum && delNum > 0)
						{
							DVNode[VName].data->sOrV.pVideos->v_num = DVNode[VName].data->sOrV.pVideos->v_num - delNum;
							break;
						}
						else
							printf("최대 삭제 가능한 수량보다 크거나 0보다 작습니다. 다시 입력해주세요.\n");
					}
				}
			}
			else
			{
				printf("해당 비디오는 모두 대여된 상태이기 때문에 삭제할 수 없습니다.\n");
			}
		}

		if (DVNode[VName].data->sOrV.pVideos->v_num == 0)
		{
			printf("%s의 모든 수량이 모두 삭제되었기 때문에 비디오 목록에서 삭제합니다.\n", DVNode[VName].data->sOrV.pVideos->v_name);

			dlDelete(vDLL, DVNode[VName].data);
		}

		for (int j = 0; j < dlCount(vDLL); j++)
		{
			DVNode[j].data = NULL;
			free(DVNode[j].data);
		}
		free(DVNode);

		dlOutputFile(vDLL, "Videos.txt");

		endMenu(sDLL, vDLL);
	}
}