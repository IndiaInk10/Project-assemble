#include "phoneInfo.h"

void dlInit(DLINKEDLIST *list) { // ���߿��Ḯ��Ʈ �ʱ�ȭ
	list->head = (NODE*)malloc(sizeof(NODE));
	list->tail = (NODE*)malloc(sizeof(NODE));
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
SA *dlSort(DLINKEDLIST *list) { // ������ �迭�� ������ �迭�� ��������� �ϰ� �ش� �迭�� �ּҰ��� ��ȯ
	int dCount = dlCount(list);

	SA *sArray = (SA*)malloc(sizeof(SA)*dCount); // �����Ҵ��� ���߿��Ḯ��Ʈ�� ����� ������ŭ
	SA temp; // ������ý� �����͸� �̵���Ű�� ���� ����
	temp.sData = (NODE*)malloc(sizeof(NODE)); // �Ҵ��� �ȵǾ��ֱ� ������ �����Ҵ�
	NODE *sort = (NODE*)malloc(sizeof(NODE)); // ���߿��Ḯ��Ʈ�� Ž���ϱ� ���� sort���
	sort = list->head->rlink;
	for (int i = 0; i < dCount; i++) // ���߿��Ḯ��Ʈ�� ó������ ������ ���鼭 �ش� �����͸� ����
	{
		strcpy_s(sArray[i].name, sizeof(sArray[i].name), sort->n_name); //�̸����� �켱������ ���ϱ⶧���� �̸��� �迭���� �̸������Ϳ� ������
		sArray[i].sData = (NODE*)malloc(sizeof(NODE));
		sArray[i].sData = sort; // �׸��� �̸��� �´� ����� �ּҰ��� �����س���
		sort = sort->rlink;
	}
	sort = NULL; // �˻��� ����� ��� �޸� ����
	free(sort);

	for (int j = 0; j < dCount - 1; j++) {
		for (int k = 0; k < dCount - 1; k++) {
			if (strcmp(sArray[k].name, sArray[k + 1].name) > 0) { // ��������� ���� �켱������� ������(���� ���� �ƽ�Ű�ڵ尪�� ũ��, ���� ���� �켱������ ���� �ڷ�)
				temp = sArray[k];
				sArray[k] = sArray[k + 1];
				sArray[k + 1] = temp;
			}
		}
	}

	return sArray; // �迭�� �ּҰ� ����
}

void dlPrint(DLINKEDLIST *list, SA *array) { // ��������� �ϰ� ���� �ش� �迭�� �ּҰ��� ������ ������������ ���
	int l;
	
	if (dlIsEmpty(list) == true)
		printf("��ȭ��ȣ�ο� ����ó�� �������� �ʽ��ϴ�.\n");
	else {
		for (l = 0; l < list->count; l++) { // ���
			if (l == 0)	{
				printf("\n");
			}
			printf("�̸�: %s || ��ȭ��ȣ: %s || �̸���: %s\n", array[l].sData->n_name, array[l].sData->n_phoneNum, array[l].sData->n_email);
		}
	}
}
NODE* dlSearchData(DLINKEDLIST *list, char *data) { // �����͸� ���� ��带 Ž���ϰ� ã�� ��� �ش� ����� �ּҰ��� ����
	if (dlIsEmpty(list) == true) {
		printf("��ȭ��ȣ�ο� ����ó�� �������� �ʽ��ϴ�.\n");
		return NULL;
	}	
	else {
		NODE *search = (NODE*)malloc(sizeof(NODE)); // �˻��� ����� �ּҸ� ������ search��� �����Ҵ�
		bool searchEd = false; // �˻��� �ƴ��� �ȵƴ��� Ȯ���ϴ� bool��
		search = list->head->rlink;
		while (search != list->tail) { // tail �������� ������ ��
			if (strcmp(data, search->n_name) == 0 || strcmp(data, search->n_phoneNum) == 0 || strcmp(data, search->n_email) == 0) { // ������ ���Ͽ� ������ 
				searchEd = true; // �˻�ǥ���ϰ�
				return search; // �ش� ����� �ּҰ� ����
			}
			search = search->rlink;
		}
		if (searchEd == false) // �˻��� �ȵ�
		{
			printf("�ش� �ڷḦ ���� ����ó�� �����ϴ�.\n");
			return NULL;
		}
	}
	return NULL;
}
void dlInsertLast(DLINKEDLIST *list, NODE *dataNode) { // �����Ͱ� �Էµ� ��带 ���߿��Ḯ��Ʈ�� �������� ����
	if (dlIsEmpty(list) == true) { // ������� ���
		list->head->rlink = dataNode; // head��
		dataNode->llink = list->head;
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode; // tail�� ��ũ
		list->tail->rlink = list->head;
		list->head->llink = list->tail;
		
		list->count += 1;
		printf("�Է��� ����ó�� ����Ǿ����ϴ�.\n");
	}
	else
	{
		list->tail->llink->rlink = dataNode; // �պκ�
		dataNode->llink = list->tail->llink; //   ����
		dataNode->rlink = list->tail;
		list->tail->llink = dataNode;

		list->count += 1;
		printf("�Է��� ����ó�� ����Ǿ����ϴ�.\n");
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
	printf("�ش� �ڷḦ ���� ����ó�� �����Ǿ����ϴ�.\n");
}