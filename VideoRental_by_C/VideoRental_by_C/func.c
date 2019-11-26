#include "func.h"

void Menu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30"); // cols=ĭ/��(����) lines=��/��(����)

	int num = 0;
	bool answer = false;

	while (answer != true) 
	{
		printf("VideoRental implemented with C Language\n\n���� �� ������ �۾��� ���ÿ�.\n");
		printf("1. �߰�(������, ����)    2. ���(�뿩 ������ ����)    3. �˻�(������, ����)\n");
		printf("4. ���� �뿩    5. ���� �ݳ�    6. ����(������, ����)    7. ����(������, ����)    8. ����\n");
		printf(">> ");

		scanf_s("%d", &num);

		while (getchar() != '\n'); // ���۸� ���

		switch (num) {
		case 1: insertData(sDLL, vDLL); answer = true; break;
		case 2: printCanRent(sDLL, vDLL); answer = true; break;
		case 3: searchData(sDLL, vDLL); answer = true; break;
		case 4: rentVideo(sDLL, vDLL); answer = true; break;
		case 5: returnVideo(sDLL, vDLL); answer = true; break;
		case 6: modifyData(sDLL, vDLL); answer = true; break;
		case 7: deleteData(sDLL, vDLL); answer = true; break;
		case 8: answer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}
}
void rentMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	int rNum = 0;
	bool rAnswer = false;

	while (rAnswer != true)
	{
		printf("���� �� ������ �۾��� ���ÿ�.\n");
		printf("1. ���� �뿩    2. ���� �ݳ�    3. �޴�    4. ����\n");
		printf(">> ");

		scanf_s("%d", &rNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (rNum) {
		case 1: rentVideo(sDLL, vDLL); rAnswer = true; break;
		case 2: returnVideo(sDLL, vDLL); rAnswer = true; break;
		case 3: Menu(sDLL, vDLL); rAnswer = true; break;
		case 4: rAnswer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}
}
void endMenu(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	int eNum = 0;
	bool eAnswer = false;

	while (eAnswer != true)
	{
		printf("���� �� ������ �۾��� ���ÿ�.\n");
		printf("1. �޴�    2. ����\n");
		printf(">> ");

		scanf_s("%d", &eNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (eNum) {
		case 1: Menu(sDLL, vDLL); eAnswer = true; break;
		case 2: eAnswer = true; dlOutputFile(sDLL, "Subs.txt"); dlOutputFile(vDLL, "Videos.txt"); return;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}
}

void insertData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	int iNum = 0;
	bool iAnswer = false;

	while(iAnswer != true) {
		printf("�Է��� ������ ���ÿ�.\n");
		printf("1. ������    2.����.\n");
		printf(">>");

		scanf_s("%d", &iNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (iNum) {
		case 1: iAnswer = true; break;
		case 2: iAnswer = true; break;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}

	if (iNum == 1) {
		NODE *ISNode = createSNode();

		if (dlIsEmpty(sDLL) == true)
			ISNode->sOrV.pSubs->s_id = 0;
		else
			ISNode->sOrV.pSubs->s_id = sDLL->tail->llink->sOrV.pSubs->s_id + 1; // �� �ڿ� �ִ� ��� id + 1

		printf("�������� �̸��� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_name, NAME_SIZE);
		printf("�������� ��ȭ��ȣ�� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_phone, PHONE_SIZE);
		printf("�������� ������ �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", ISNode->sOrV.pSubs->s_reside, RESIDE_SIZE);

		dlInsertLast(sDLL, ISNode);

		dlOutputFile(sDLL, "Subs.txt");

		while (getchar() != '\n');

		rentMenu(sDLL, vDLL);
	}
	else {
		NODE *IVNode = createVNode();

		printf("������ �̸��� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", IVNode->sOrV.pVideos->v_name, SRENTNAME_SIZE);
		if (dlModifyData(vDLL, "Videos", IVNode->sOrV.pVideos->v_name) != NULL) // �̹� �ִ� ���� �̸��� �ԷµǸ�
		{
			SA *MVNode;
			int addNum = 0;

			MVNode = dlModifyData(vDLL, "Videos", IVNode->sOrV.pVideos->v_name);

			printf("�ش� ������ �̹� �����մϴ�.");
			while (1)
			{
				printf("�߰��Ǵ� ������ �Է��Ͻÿ�.\n\n>> ");
				if (scanf_s("%d", &addNum) == 0)
				{
					printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
						printf("0 ���� ���� ���� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");
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
			printf("������ �帣�� �Է��Ͻÿ�.\n\n>> ");
			scanf_s("%s", IVNode->sOrV.pVideos->v_genre, GENRE_SIZE);
			printf("������ ������ �Է��Ͻÿ�.\n\n>> ");
			scanf_s("%s", IVNode->sOrV.pVideos->v_author, NAME_SIZE);
			while (strlen(IVNode->sOrV.pVideos->VRLday) != 10)
			{
				printf("�������� �Է��Ͻÿ�. ex) 0000-00-00\n\n>> ");
				scanf_s("%s", IVNode->sOrV.pVideos->VRLday, SRNDAY_SIZE);
				if (strlen(IVNode->sOrV.pVideos->VRLday) != 10)
				{
					printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}
			while (1)
			{
				printf("������ ������ �Է��Ͻÿ�.\n\n>> ");
				if (scanf_s("%d", &(IVNode->sOrV.pVideos->v_num)) == 0)
				{
					printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
						printf("0 ���� ���� ���� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");
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

	printf("�뿩������ ���� ���\n");
	dlPrint(dlSort(vDLL));

	rentMenu(sDLL, vDLL);
}
void searchData(DLINKEDLIST *sDLL, DLINKEDLIST *vDLL) {
	system("mode con cols=100 lines=30");
	int sNum = 0;
	bool sAnswer = false;

	while (sAnswer != true) {
		printf("�˻��� ������ ���ÿ�.\n");
		printf("1. ������    2.����.\n");
		printf(">>");

		scanf_s("%d", &sNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (sNum) {
		case 1: sAnswer = true; break;
		case 2: sAnswer = true; break;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}

	if (sNum == 1)
	{
		char search[NAME_SIZE]; // ���� ū ������ ������ ����

		printf("�˻��� ������ �Է��Ͻÿ�. ex)�̸� ��ȭ��ȣ ������ ��...\n\n>> ");
		scanf_s("%s", search, NAME_SIZE);

		dlSearchData(sDLL, "Subs", search);
	}
	else
	{
		char search[NAME_SIZE];

		printf("�˻��� ������ �Է��Ͻÿ�. ex)�帣 ������ ���� ������ ��...\n\n>> ");
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
		printf("�뿩�� ������ ������ �Է��Ͻÿ�. ex)�̸� ��ȭ��ȣ ������ ��...\n\n>> ");
		scanf_s("%s", RSearch, NAME_SIZE);
		RSNode = dlModifyData(sDLL, "Subs", RSearch);

		if (RSNode != NULL)
			break;
		else
		{
			printf("�ش� ������ ���� �����ڴ� �����ϴ�. �ٽ� �Է����ּ���.\n");
		}
	}

	dlSearchData(sDLL, "Subs", RSearch);

	while (1)
	{
		printf("���� �� �ڽ��� ID�� �Է��Ͻÿ�.\n\n>> ");

		if (scanf_s("%d", &ID) == 0)
		{
			printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");

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
				printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}
	}

	if (RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum == 3)
	{
		printf("%s�Բ����� �� �뿩���� Ƚ��(3ȸ)�� �� ����ϼ̱� ������ �� �̻� �뿩�� �� �����ϴ�.\n", RSNode[ID].data->sOrV.pSubs->s_name);

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

		printf("�뿩������ ���� ���\n");						  // ������ �ִ� ���� ��ϸ� ������ ����
		dlPrint(dlSort(vDLL));
		
		printf("���� �� �뿩�� ������ �̸��� �Է��Ͻÿ�.\n\n>> ");	  // ���� ������ �̸��� ���� ��
		scanf_s("%s", RSearch, NAME_SIZE);
		RVNode = dlModifyData(vDLL, "Videos", RSearch);

		strcpy_s(rVRLdate, SRNDAY_SIZE, RVNode[0].data->sOrV.pVideos->VRLday);
		VRLDate = changeInteger(rVRLdate);
		rDate = getDate(); // ���� ��¥�� �޾ƿ���

		if (VRLDate->y <= rDate->y - 16) // �ּ� �뿩��� 2000������ ����
		{
			addFee = 2000;
		}
		else
		{
			addFee = addFee - (rDate->y / 3 - VRLDate->y / 3) * 500; // ���� �⵵ �Ʒ�(-1)�⵵�� ������ ������ ��ȭ�� 3���� �������� -500 ��
		}
		
		printf("�ش� ������ �뿩��� %d�Դϴ�.\n", addFee);

		for (int i = 0; i < 3; i++)
		{
			if (strlen(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0])) == 0)
			{
				strcpy_s(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[i][0]), SRENTNAME_SIZE, RVNode[0].data->sOrV.pVideos->v_name);
				strcpy_s(&(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[i][0]), SRNDAY_SIZE, changeString(rDate->y, rDate->m, rDate->d));
				break;
			}
		}

		RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum += 1; // ������ �뿩 Ƚ�� ����
		RVNode[0].data->sOrV.pVideos->v_rentNum += 1; // ���� �뿩�� Ƚ�� ����

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
		printf("�ݳ��� ������ ������ �Է��Ͻÿ�. ex)�̸� ��ȭ��ȣ ������ ��...\n\n>> ");
		scanf_s("%s", RSearch, NAME_SIZE);
		RSNode = dlModifyData(sDLL, "Subs", RSearch);

		if (RSNode != NULL)
			break;
		else
		{
			printf("�ش� ������ ���� �����ڴ� �����ϴ�. �ٽ� �Է����ּ���.\n");
		}
	}

	dlSearchData(sDLL, "Subs", RSearch);

	while (1)
	{
		printf("���� �� �ڽ��� ID�� �Է��Ͻÿ�.\n\n>> ");

		if (scanf_s("%d", &ID) == 0)
		{
			printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");

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
				printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}
	}

	if (RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum == 0)
	{
		printf("%s�Բ����� �뿩�� ������ �����ϴ�.\n", RSNode[ID].data->sOrV.pSubs->s_name);

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

		printf("%s���� �뿩�� ���� ����� ", RSNode[ID].data->sOrV.pSubs->s_name);
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
		printf("�Դϴ�.\n");

		printf("���� �� �ݳ��� ������ �̸��� �Է��Ͻÿ�.\n\n>> ");	  // �ݳ��� ������ �̸��� ���� ��
		scanf_s("%s", RSearch, SRENTNAME_SIZE);
		RVNode = dlModifyData(vDLL, "Videos", RSearch);

		for (int j = 0; j < RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum; j++)
		{
			if (strcmp(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[j][0]), RVNode[0].data->sOrV.pVideos->v_name) == 0)
			{
				strcpy_s(rVRLdate, SRNDAY_SIZE, &(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[j][0]));
				rentDate = changeInteger(rVRLdate);

				memset(&(RSNode[ID].data->sOrV.pSubs->s_rent.sRentName[j][0]), 0, SRENTNAME_SIZE); // �뿩�� ��� ����
				memset(&(RSNode[ID].data->sOrV.pSubs->s_rent.SRNday[j][0]), 0, SRNDAY_SIZE); // �뿩�� ��� ����
			}
		}

		rDate = getDate(); // ���� ��¥�� �޾ƿ���

		if (DateCal(*rDate, *rentDate) > 14)
		{
			printf("��ü��� %d���Դϴ�.\n", (DateCal(*rDate, *rentDate) - 14) * 100); // ��ü��� �ϴ� 100������ ��� ���ں�
		}
		printf("�ݳ��Ǿ����ϴ�.\n");

		RSNode[ID].data->sOrV.pSubs->s_rent.sRentNum -= 1; // ������ �뿩 Ƚ�� ����
		RVNode[0].data->sOrV.pVideos->v_rentNum -= 1; // ���� �뿩�� Ƚ�� ����

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
		printf("������ ������ ���ÿ�.\n");
		printf("1. ������    2.����.\n");
		printf(">>");

		scanf_s("%d", &mNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (mNum) {
		case 1: mAnswer = true; break;
		case 2: mAnswer = true; break;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}

	if (mNum == 1) {
		char MSearch[NAME_SIZE];
		int ID;
		SA *MSNode;

		while (1)
		{
			printf("������ ������ ������ �Է��Ͻÿ�. ex)�̸� ��ȭ��ȣ ������ ��...\n\n>> ");
			scanf_s("%s", MSearch, NAME_SIZE);
			MSNode = dlModifyData(sDLL, "Subs", MSearch);

			if (MSNode != NULL)
				break;
			else
			{
				printf("�ش� ������ ���� �����ڴ� �����ϴ�. �ٽ� �Է����ּ���.\n");
			}
		}

		dlSearchData(sDLL, "Subs", MSearch);

		while (1)
		{
			printf("���� �� �ڽ��� ID�� �Է��Ͻÿ�.\n\n>> ");

			if (scanf_s("%d", &ID) == 0)
			{
				printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");

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
					printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}
		}

		if (MSNode[ID].data->sOrV.pSubs->s_rent.sRentNum != 0)
		{
			printf("�ش� �����ڴ� �뿩�� ������ �ֱ� ������ ������ �� �����ϴ�.\n");

			for (int j = 0; j < dlCount(sDLL); j++)
			{
				MSNode[j].data = NULL;
				free(MSNode[j].data);
			}
			free(MSNode);

			rentMenu(sDLL, vDLL);
		}

		printf("������ �̸��� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", MSNode[ID].data->sOrV.pSubs->s_name, NAME_SIZE);
		printf("������ ��ȭ��ȣ�� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", MSNode[ID].data->sOrV.pSubs->s_phone, PHONE_SIZE);
		printf("������ ������ �Է��Ͻÿ�.\n\n>> ");
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
			printf("������ ������ ������ �Է��Ͻÿ�. ex)�帣 ������ ���� ������ ��...\n\n>> ");
			scanf_s("%s", MSearch, NAME_SIZE);
			MVNode = dlModifyData(vDLL, "Videos", MSearch);

			if (MVNode != NULL)
				break;
			else
			{
				printf("�ش� ������ ���� ������ �����ϴ�. �ٽ� �Է����ּ���.\n");
			}
		}

		dlSearchData(vDLL, "Videos", MSearch);

		while (1)
		{
			printf("���� �� ���� �̸��� �Է��Ͻÿ�.\n\n>> ");
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
				printf("�߸��� ���� �̸� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}

		if (MVNode[VName].data->sOrV.pVideos->v_rentNum != 0)
		{
			printf("�ش� ������ �뿩�� �����ڰ� �ֱ� ������ ������ �� �����ϴ�.\n");

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
			printf("���� �̸��� �����Ͻðڽ��ϴ�?\n");
			printf("1. ��    2. �ƴϿ�\n\n>> ");
			if (scanf_s("%d", &MNameNum) == 0)
			{
				printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

				while (getchar() != '\n');
			}
			else if (MNameNum == 1)
			{
				printf("������ �̸��� �Է��Ͻÿ�.\n\n>> ");
				scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_name, SRENTNAME_SIZE);
				break;
			}
			else if (MNameNum == 2)
			{
				break;
			}
			else
			{
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}
		

		printf("������ �帣�� �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_genre, GENRE_SIZE);
		printf("������ ������ �Է��Ͻÿ�.\n\n>> ");
		scanf_s("%s", MVNode[VName].data->sOrV.pVideos->v_author, NAME_SIZE);
		while (strlen(MVNode[VName].data->sOrV.pVideos->VRLday) != 10)
		{
			printf("������ �������� �Է��Ͻÿ�. ex) 0000-00-00\n\n>> ");
			scanf_s("%s", MVNode[VName].data->sOrV.pVideos->VRLday, SRNDAY_SIZE);
			if (strlen(MVNode[VName].data->sOrV.pVideos->VRLday) != 10)
			{
				printf("�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}
		if (MVNode[VName].data->sOrV.pVideos->v_num > 0 && MVNode[VName].data->sOrV.pVideos->v_rentNum == 0)
		{
			printf("������ ������ �Է��Ͻÿ�(�ִ� ���� ������ ����: %d)\n\n>> ", MVNode[VName].data->sOrV.pVideos->v_num);
			while (1)
			{
				if (scanf_s("%d", &modiNum) == 0)
				{
					printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
				printf("������ ������ �Է��Ͻÿ�(�ִ� ���� ������ ����: %d �̻�)\n\n>> ", MVNode[VName].data->sOrV.pVideos->v_rentNum);
				while (1)
				{
					if (scanf_s("%d", &modiNum) == 0)  // �뿩�� ���� �� ���� ���� ���� ���� �Ұ���
					{
						printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
							printf("�ִ� ���� ������ �������� �����ϴ�. �ٽ� �Է����ּ���.\n");
					}
				}
			}
			else
			{
				printf("�ش� ������ ��� �뿩�� �����̱� ������ ������ �� �����ϴ�.\n");
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
		printf("������ ������ ���ÿ�.\n");
		printf("1. ������    2.����.\n");
		printf(">>");

		scanf_s("%d", &dNum);

		while (getchar() != '\n'); // ���۸� ���

		switch (dNum) {
		case 1: dAnswer = true; break;
		case 2: dAnswer = true; break;

		default: printf("========================================\n"); printf("�׷� �۾��� �����ϴ�.\n"); printf("========================================\n"); break;
		}
	}

	if (dNum == 1) {
		char DSearch[NAME_SIZE];
		int ID;
		SA *DSNode;

		while (1)
		{
			printf("������ ������ ������ �Է��Ͻÿ�. ex)�̸� ��ȭ��ȣ ������ ��...\n\n>> ");
			scanf_s("%s", DSearch, NAME_SIZE);
			DSNode = dlModifyData(sDLL, "Subs", DSearch);

			if (DSNode != NULL)
				break;
			else
			{
				printf("�ش� ������ ���� �����ڴ� �����ϴ�. �ٽ� �Է����ּ���.\n");
			}
		}
		
		dlSearchData(sDLL, "Subs", DSearch);

		while (1)
		{
			printf("���� �� �ڽ��� ID�� �Է��Ͻÿ�.\n\n>> ");

			if (scanf_s("%d", &ID) == 0)
			{
				printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");

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
					printf("�߸��� ID �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
				}
			}
		}

		if (DSNode[ID].data->sOrV.pSubs->s_rent.sRentNum != 0)
		{
			printf("%s�Բ����� �뿩�� ������ �ֱ� ������ ������ ������ �� �����ϴ�.\n", DSNode[ID].data->sOrV.pSubs->s_name);

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
			printf("������ ������ ������ �Է��Ͻÿ�. ex)�帣 ������ ���� ������ ��...\n\n>> ");
			scanf_s("%s", DVSearch, NAME_SIZE);
			DVNode = dlModifyData(vDLL, "Videos", DVSearch);

			if (DVNode != NULL)
				break;
			else
			{
				printf("�ش� ������ ���� ������ �����ϴ�. �ٽ� �Է����ּ���.\n");
			}
		}

		dlSearchData(vDLL, "Videos", DVSearch);

		while (1)
		{
			printf("���� �� ���� �̸��� �Է��Ͻÿ�.\n\n>> ");
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
				printf("�߸��� ���� �̸� �Է��Դϴ�. �ٽ� �Է����ּ���.\n");
			}
		}

		if (DVNode[VName].data->sOrV.pVideos->v_num > 0 && DVNode[VName].data->sOrV.pVideos->v_rentNum == 0)
		{
			printf("������ ������ �Է��Ͻÿ�(�ִ� ���� ������ ����: %d)\n\n>> ", DVNode[VName].data->sOrV.pVideos->v_num);
			while (1)
			{
				if (scanf_s("%d", &delNum) == 0)
				{
					printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
				printf("������ ������ �Է��Ͻÿ�(�ִ� ���� ������ ����: %d ����)\n\n>> ", DVNode[VName].data->sOrV.pVideos->v_num - DVNode[VName].data->sOrV.pVideos->v_rentNum);
				while (1)
				{
					if (scanf_s("%d", &delNum) == 0)  // �뿩�� ���� �� ���� ���� ���� ���� �Ұ���
					{
						printf("���ڰ� �ԷµǾ����ϴ�. �ٽ� �Է����ּ���.\n");

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
							printf("�ִ� ���� ������ �������� ũ�ų� 0���� �۽��ϴ�. �ٽ� �Է����ּ���.\n");
					}
				}
			}
			else
			{
				printf("�ش� ������ ��� �뿩�� �����̱� ������ ������ �� �����ϴ�.\n");
			}
		}

		if (DVNode[VName].data->sOrV.pVideos->v_num == 0)
		{
			printf("%s�� ��� ������ ��� �����Ǿ��� ������ ���� ��Ͽ��� �����մϴ�.\n", DVNode[VName].data->sOrV.pVideos->v_name);

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