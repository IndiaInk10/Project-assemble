#include "DoubleLinkedList.h"

NODE *createSNode() { // ������ ������ �ٷ�� ���
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	subs *data = (subs*)malloc(sizeof(subs));
	memset(newNode, 0, sizeof(NODE));
	memset(&(data->s_rent), 0, sizeof(sRent));
	memset(data, 0, sizeof(subs));
	

	newNode->llink = newNode->rlink = NULL;
	newNode->sOrV.pSubs = data;

	return newNode;
}

NODE *createVNode() { // ���� ������ �ٷ�� ���
	NODE *newNode = (NODE*)malloc(sizeof(NODE));
	videos *data = (videos*)malloc(sizeof(videos));
	memset(newNode, 0, sizeof(NODE));
	memset(data, 0, sizeof(videos)); 

	newNode->llink = newNode->rlink = NULL;
	newNode->sOrV.pVideos = data;

	return newNode;	
}					
					
void dlSInit(DLINKEDLIST *list) { // ������ ���߿��Ḯ��Ʈ �ʱ�ȭ
	list->head = createSNode();
	list->tail = createSNode();
	list->head->rlink = list->head->llink = NULL;
	list->tail->rlink = list->tail->llink = NULL;
	list->count = 0;
}
void dlVInit(DLINKEDLIST *list) { // ���� ���߿��Ḯ��Ʈ �ʱ�ȭ
	list->head = createVNode();
	list->tail = createVNode();
	list->head->rlink = list->head->llink = NULL;
	list->tail->rlink = list->tail->llink = NULL;
	list->count = 0;
}

bool dlIsEmpty(DLINKEDLIST *list) { // ����ִ��� �������߿��Ḯ��Ʈ�� �ƴϱ� ������ ��ũ�� �ٽ��� head->rlink�� tail->llink + count�� �߰� ������ +-�� �̷����
	if (list->head->rlink == NULL && list->tail->llink == NULL && list->count == 0)
		return true;
	else
		return false;
}
int dlCount(DLINKEDLIST *list) { // Ȥ�ó� ���߿��Ḯ��Ʈ�� ����� ������ �˱� ���� �Լ�
	return list->count;
}

void dlInputFile(DLINKEDLIST *list, char *fileName) { // ������ ���߿��Ḯ��Ʈ�� �Է�
	if (strcmp(fileName, "Subs.txt") == 0)  //  ó���� ���ڷ� ���ϸ��� �޾ƿͼ� �� �� ������ ���� ���� ���� �Է��� �޴´�.
	{

		FILE *sFin;
		fopen_s(&sFin, fileName, "rt");
		
		if(sFin == NULL) { // ������ �������� ���� ��
			printf("Subs������ �������� �ʽ��ϴ�...\n");
			fclose(sFin);
		}
		else // sFin != NULL ������ ������ �� 
		{
			fseek(sFin, 0, SEEK_END); // ���� ������ ����

			printf("Subs���� �н��ϴ�...\n");
			if (ftell(sFin) == 0) { // �ش� ������ ���̸� ���� ��������� ����ó��
				printf("Subs������ ����ֽ��ϴ�...\n");
				fclose(sFin);
			}
			else // �ƴϸ� �Է� ����
			{
				fseek(sFin, 0, SEEK_SET); // �ٽ� ���� ó������ ���� 

				char sBuffer[522];
				char *div = "|";
				char *context;
				char *tok[11];

				printf("Subs���Ͽ��� ������ ���� �������� ��... \n");
				while (feof(sFin) == 0) // ������ ���� �ƴ� ����
				{
					NODE *sNode = createSNode(); // ������ ��� ����
					int tok4Num = 0, count = 0;

					fgets(sBuffer, sizeof(sBuffer), sFin); // ���۸� �������� ���Ͽ��� �� ���� �а�

					context = sBuffer;

					for (int i = 0; i < 11; i++)
					{
						tok[i] = strtok_s(context, div, &context); //  ���� ���ڸ� ����  �����͸� �߶� ����

						if (i == 4) // ���� ������ �̻��� ������ �Ʒ��� ������ ���� �Ǻ��Ͽ� �� ����
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
					// ������ ������ ����
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

					dlInsertLast(list, sNode); // ��� ����
				}

				fclose(sFin);
			}
		}
	}
	else if (strcmp(fileName, "Videos.txt") == 0) 
	{
		FILE *vFin;
		fopen_s(&vFin, fileName, "rt");
		
		if(vFin == NULL) { // ������ �������� ���� ��
			printf("Videos������ �������� �ʽ��ϴ�...\n");
			fclose(vFin);
		}
		else // vfin != NULL ������ ������ ��
		{
			fseek(vFin, 0, SEEK_END); // ���� ������ ��

			printf("Videos���� �н��ϴ�...\n");
			
			if (ftell(vFin) == 0) { // ���̰� 0�̸� ������ �������
				printf("Videos������ ����ֽ��ϴ�...\n");
				fclose(vFin);
			}
			else 
			{
				fseek(vFin, 0, SEEK_SET); // �ٽ� ������ ó������ ��

				char vBuffer[264];
				char *div = "|";
				char *context;
				char *tok[6];

				printf("���� ��� �������� ��...\n");
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

		if (sFout == NULL) { // ������ �������� ���� ��
			printf("������ �������� �ʾ� ���� �����Ͽ� �����մϴ�...\n");
		}
		else // sFin != NULL ������ ������ �� 
		{
			printf("���� ������ �����ϰ� ���� �����Ͽ� �����մϴ�...\n");
		}

		NODE *sSave = createSNode(); // ���� �� Ž���� ��� ����

		for (sSave = list->head->rlink; sSave != list->tail; sSave = sSave->rlink)
		{
			char numBuffer[7];
			
			// int�� �����Ͱ� ������ ���ڿ� �����ͷ� �ٲپ� ��� �ϰ� ������ ���ڿ� �����͵��� �׳� ���
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
				// �ش� ���ڿ��� ��� ���� ������ ���(���Ͽ� ����)
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

		if (vFout == NULL) { // ������ �������� ���� ��
			printf("������ �������� �ʾ� ���� �����Ͽ� �����մϴ�...\n");
		}
		else // sfin != NULL ������ ������ �� 
		{
			printf("���� ������ �����ϰ� ���� �����Ͽ� �����մϴ�...\n");
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

SA *dlSort(DLINKEDLIST *list) { // ������ �迭�� ������ �迭�� ��������� �ϰ� �ش� �迭�� �ּҰ��� ��ȯ
	int dCount = dlCount(list);

	if (dCount == 0)
		printf("�뿩������ ������ �����ϴ�.\n");
	else 
	{
		int rentableNum = 0;

		SA *sArray = (SA*)malloc(sizeof(SA)*dCount); // �����Ҵ��� ���߿��Ḯ��Ʈ�� ����� ������ŭ
		memset(sArray, 0, sizeof(SA)*dCount);
		SA temp = { 0, }; // ������ý� �����͸� �̵���Ű�� ���� ����
		temp.data = (NODE*)malloc(sizeof(NODE)); // �Ҵ��� �ȵǾ��ֱ� ������ �����Ҵ�
		NODE *sort = createVNode(); // ���߿��Ḯ��Ʈ�� Ž���ϱ� ���� sort���
		sort = list->head->rlink;

		for (sort = list->head->rlink; sort != list->tail; sort = sort->rlink) // ���߿��Ḯ��Ʈ�� ó������ ������ ���鼭 �ش� �����͸� ����
		{
			if (((sort->sOrV.pVideos->v_num) - (sort->sOrV.pVideos->v_rentNum)) > 0) {
				printf("�뿩������ ���� ������...\n");
				strcpy_s(sArray[rentableNum].name, SRENTNAME_SIZE, sort->sOrV.pVideos->v_name); //�̸����� �켱������ ���ϱ⶧���� �̸��� �迭���� �̸������Ϳ� ������
				sArray[rentableNum].data = (NODE*)malloc(sizeof(NODE));
				memset(sArray[rentableNum].data, 0, sizeof(NODE));
				sArray[rentableNum++].data = sort; // �׸��� �̸��� �´� �������� �ּҰ��� �����س���
			}
			else {
				printf("�Ѿ�� ��...\n");
			}
		}
		sort = NULL; // �˻��� ����� ��� �޸� ����
		free(sort);

		for (int j = 0; j < rentableNum - 2; j++)
		{
			for (int k = 0; k < rentableNum - 2; k++)
			{
				if (strcmp(sArray[k + 1].name, "") == 0) {
					break;
				}
				else if (strcmp(sArray[k].name, sArray[k + 1].name) > 0) { // ��������� ���� �켱������� ������(���� ���� �ƽ�Ű�ڵ尪�� ũ��, ���� ���� �켱������ ���� �ڷ�)
					temp = sArray[k];
					sArray[k] = sArray[k + 1];
					sArray[k + 1] = temp;
				}
			}
		}
		sArray[0].count = rentableNum;

		return sArray; // �迭�� �ּҰ� ����
	}
	
	return NULL;
}

void dlPrint(SA *array) { // ��������� �ϰ� ���� �ش� �迭�� �ּҰ��� ������ ������������ ���
	if (array == 0)
		return;
	else 
	{
		for (int l = 0; l < array[0].count; l++) 
		{ // ���
			if (l == 0)	{
				printf("\n");
			}
			printf("�帣: %s || ���� �̸�: %s || ����: %s || ������: %s\n", array[l].data->sOrV.pVideos->v_genre, array[l].data->sOrV.pVideos->v_name, array[l].data->sOrV.pVideos->v_author, array[l].data->sOrV.pVideos->VRLday);
		}
	}
	//free(array);
}

void dlSearchData(DLINKEDLIST *list, char* dataName, char *data) { 
	if (strcmp(dataName, "Subs") == 0) 
	{
		if (dlIsEmpty(list) == true) {
			printf("������ ������ �������� �ʽ��ϴ�.\n");
		}
		else {
			NODE *search = createSNode(); // Ž���� ��� ����
			bool searchEd = false; // �˻��� �ƴ��� �ȵƴ��� Ȯ���ϴ� bool��
			search = list->head->rlink;

			while (search != list->tail) { // tail �������� ������ ��
				if (strcmp(data, search->sOrV.pSubs->s_name) == 0 || strcmp(data, search->sOrV.pSubs->s_phone) == 0 || strcmp(data, search->sOrV.pSubs->s_reside) == 0) {// ������ ���Ͽ� ������ 
					searchEd = true; // �˻�ǥ���ϰ�
					printf("ID: %d || �̸�: %s || ��ȭ��ȣ: %s || ������: %s || ", search->sOrV.pSubs->s_id, search->sOrV.pSubs->s_name, search->sOrV.pSubs->s_phone, search->sOrV.pSubs->s_reside);
					if (search->sOrV.pSubs->s_rent.sRentNum == 0) 
					{
						printf("�뿩�� ������ �����ϴ�.\n");
					}
					else if (search->sOrV.pSubs->s_rent.sRentNum > 0)
					{
						printf("�뿩�� ���� ���: %s", &(search->sOrV.pSubs->s_rent.sRentName[0][0]));
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
			if (searchEd == false) // �˻��� �ȵ�
			{
				printf("�ش� �ڷḦ ���� �����ڴ� �����ϴ�.\n");
			}
		}
	}
	else if (strcmp(dataName, "Videos") == 0)
	{
		if (dlIsEmpty(list) == true) {
			printf("���� ������ �������� �ʽ��ϴ�.\n");
		}
		else {
			NODE *search = createSNode(); // Ž���� ��� ����
			bool searchEd = false; // �˻��� �ƴ��� �ȵƴ��� Ȯ���ϴ� bool��
			search = list->head->rlink;

			while (search != list->tail) { // tail �������� ������ ��
				if (strcmp(data, search->sOrV.pVideos->v_genre) == 0 || strcmp(data, search->sOrV.pVideos->v_name) == 0 || strcmp(data, search->sOrV.pVideos->v_author) == 0) { // ������ ���Ͽ� ������ 
					searchEd = true; // �˻�ǥ���ϰ�
					printf("�帣: %s || ���� �̸�: %s || ����: %s || ������: %s || ", search->sOrV.pVideos->v_genre, search->sOrV.pVideos->v_name, search->sOrV.pVideos->v_author, search->sOrV.pVideos->VRLday);
					if (((search->sOrV.pVideos->v_num) - (search->sOrV.pVideos->v_rentNum)) == 0)
					{
						printf("�뿩 ������ ���� ��� �����ϴ�.\n");
					}
					else
					{
						printf("���� ���: %d\n", ((search->sOrV.pVideos->v_num) - (search->sOrV.pVideos->v_rentNum)));
					}
				}
				search = search->rlink;
			}
			if (searchEd == false) // �˻��� �ȵ�
			{
				printf("�ش� �ڷḦ ���� ������ �����ϴ�.\n");
			}
		}
	}
	else {
		printf("�׷� �̸��� ������ �����ϴ�.\n");
	}
}
SA* dlModifyData(DLINKEDLIST *list, char* dataName, char *data) { // �����͸� ���� ��带 Ž���ϰ� ã�� ��� �ش� ����� �ּҰ��� ����
	if (strcmp(dataName, "Subs") == 0)
	{
		if (dlIsEmpty(list) == true) {
			//printf("������ ������ �������� �ʽ��ϴ�.\n");
			return NULL;
		}
		else {
			int sSearchNum = 0;
			NODE *sSearch = createSNode(); // �˻��� ����� �ּҸ� ������ search��� �����Ҵ�
			SA *sSearchEdNode = (SA*)malloc(sizeof(SA)*dlCount(list)); // ����� �ּҰ��� �޴� ����� �ּҰ��� �����Ҵ�
			memset(sSearchEdNode, 0, sizeof(SA)*dlCount(list));

			bool sSearchEd = false; // �˻��� �ƴ��� �ȵƴ��� Ȯ���ϴ� bool��
			sSearch = list->head->rlink;
			while (sSearch != list->tail) { // tail �������� ������ ��
				if (strcmp(data, sSearch->sOrV.pSubs->s_name) == 0 || strcmp(data, sSearch->sOrV.pSubs->s_phone) == 0 || strcmp(data, sSearch->sOrV.pSubs->s_reside) == 0) {// ������ ���Ͽ� ������
					sSearchEd = true; // �˻�ǥ���ϰ�
					sSearchEdNode[sSearchNum++].data = sSearch; // �ش� �ڷḦ ���� ����� �ּҰ� ����
				}
				sSearch = sSearch->rlink;
			}
			sSearch = NULL; // �˻��� ����� ��� �޸� ����
			free(sSearch);
			
			if (sSearchEd == true)
			{
				sSearchEdNode[0].count = sSearchNum;
				return sSearchEdNode;
			}
			else // �˻��� �ȵ�
			{
				//printf("�ش� �ڷḦ ���� �����ڴ� �����ϴ�.\n");
				return NULL;
			}
		}
	}
	else if (strcmp(dataName, "Videos") == 0)
	{
		if (dlIsEmpty(list) == true) {
			printf("���� ������ �������� �ʽ��ϴ�.\n");
			return NULL;
		}
		else {
			int vSearchNum = 0;
			NODE *vSearch = createSNode(); // �˻��� ����� �ּҸ� ������ search��� �����Ҵ�
			SA *vSearchEdNode = (SA*)malloc(sizeof(SA)*dlCount(list)); // ����� �ּҰ��� �޴� ����� �ּҰ��� �����Ҵ�
			memset(vSearchEdNode, 0, sizeof(SA)*dlCount(list));

			bool vSearchEd = false; // �˻��� �ƴ��� �ȵƴ��� Ȯ���ϴ� bool��
			vSearch = list->head->rlink;
			while (vSearch != list->tail) { // tail �������� ������ ��
				if (strcmp(data, vSearch->sOrV.pVideos->v_genre) == 0 || strcmp(data, vSearch->sOrV.pVideos->v_name) == 0 || strcmp(data, vSearch->sOrV.pVideos->v_author) == 0) { // ������ ���Ͽ� ������ 
					vSearchEd = true; // �˻�ǥ���ϰ�
					vSearchEdNode[vSearchNum++].data = vSearch;
				}
				vSearch = vSearch->rlink;
			}
			vSearch = NULL; // �˻��� ����� ��� �޸� ����
			free(vSearch);

			if (vSearchEd == true)
			{
				vSearchEdNode[0].count = vSearchNum;
				return vSearchEdNode;
			}
			else // �˻��� �ȵ�
			{
				printf("�ش� �ڷḦ ���� ������ �����ϴ�.\n");
				return NULL;
			}
		}
	}
	else {
		printf("�׷� �̸��� ������ �����ϴ�.\n");
		return NULL;
	}

	return NULL;
}

void dlInsertLast(DLINKEDLIST *list, NODE *dataNode) { // �����Ͱ� �Էµ� ��带 ���߿��Ḯ��Ʈ�� �������� ����
	if (dlIsEmpty(list) == true) { // ������� ���
		list->head->rlink = dataNode; // head��
		dataNode->llink = list->head;
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode; // tail�� ��ũ

		list->count += 1;
		printf("�Է��� ù ������ ����Ǿ����ϴ�.\n");
	}
	else
	{
		list->tail->llink->rlink = dataNode; // �պκ�
		dataNode->llink = list->tail->llink; //   ����
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode;

		list->count += 1;
		printf("�Է��� ������ ����Ǿ����ϴ�.\n");
	}
}

void dlDelete(DLINKEDLIST *list, NODE *search) { // �Էµ� ����� �ּҰ��� �޸� ����
	NODE *remove = (NODE*)malloc(sizeof(NODE)); 
	if (list->count == 1) { // �ϳ��� ���� ���, ���� ���߿��Ḯ��Ʈ�� �ƴϱ⿡ ����
		list->head->rlink = NULL;
		list->tail->llink = NULL;
		list->count -= 1;
	}
	else { // �ٸ� ���� ������ ����� �� ���� �� ��带 ����
		remove = search;
		remove->llink->rlink = remove->rlink;
		remove->rlink->llink = remove->llink;
		list->count -= 1;
	}

	free(remove);
	printf("�ش� �ڷḦ ���� ������ �����Ǿ����ϴ�.\n");
}