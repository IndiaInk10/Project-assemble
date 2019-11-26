#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 10 // �迭�� ũ��
typedef struct
{
	float coef; // ���� ���
	int expon; // ���� ����
} polynomial;

polynomial termsA[MAX_TERMS] = { 0, }, termsB[MAX_TERMS] = { 0, }, termsC[2 * MAX_TERMS] = { 0, }; // �迭�� 0���� �ʱ�ȭ
int avail = 0; // ���� ������ ���׽��� �迭�� ��ġ �� termsC[avail = 0]

// �� ���� ���� ��
char compare(int a, int b) // int �Է� �� �� char�� ���
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// ���ο� ���� ���׽Ŀ� �߰��Ѵ�.
void attach(float coef, int expon)
{
	if (avail > 2 * MAX_TERMS) // ���׽� C�� �ִ� ����, �� ���׽��� ���� ������ �ϳ��� �� ��ĥ �� �ִ� 20��
	{
		fprintf(stderr, "���� ������ �ʹ� ����\n"); // �迭�� �ִ� ������ ���� �� ���� ǥ��
		exit(1);
	}
	termsC[avail].coef = coef;
	termsC[avail].expon = expon;
	avail++; // ���� �迭�� �Է��ϱ� ���� ��������
}

// C = A + B
void poly_add2(int Ae, int Be, int *Ce) // �� �迭�� �ִ������ �Է¹޴´�, �� �迭�� ���������̱� ������  �ִ������ �Է¹޴� ���� ����
{
	float tempcoef = 0.0; // �Ǽ��� ���� ���� �� �ʱ�ȭ
	int As = 0, Bs = 0; // ���׽� A, B�� �迭�� ��ġ ���� ǥ���� ���� ���� �� �ʱ�ȭ

	while (As <= Ae && Bs <= Be) // ���׽� A, B �迭 ��� ����� �迭 ���� �ȿ� ���� �� ���� �ݺ�
	{
		switch (compare(termsA[As].expon, termsB[Bs].expon))
		{
		case '>': // A�� ���� > B�� ����
		{
			attach(termsA[As].coef, termsA[As].expon); // A�� ������ �� Ŭ ��� �ش� ������ ����� ������ ���׽� C�� �Է�
			As++;	break; // ���׽� A�� ���� �迭�� �̵� 
		}
		case '=': // A�� ���� = B�� ����
		{
			tempcoef = termsA[As].coef + termsB[Bs].coef; // A�� B�� ������ ���� �� ����� �����ش�
			if (tempcoef) // = if (tempcoef != 0)
			{
				attach(tempcoef, termsA[As].expon); // ������ ����� C�� �־��ְ�, ������ A���� �ֵ� B���� �ֵ� �� ����
			}
			As++; Bs++; tempcoef = 0.0;  break; // �� ���׽��� �迭 ���� ��ġ��
		}
		case '<': // A�� ���� < B�� ����
		{
			attach(termsB[Bs].coef, termsB[Bs].expon); // B�� ������ �� Ŭ ��� �ش� ������ ����� ������ ���׽� C�� �Է�
			Bs++;	break; // ���׽� B�� ���� �迭�� �̵�
		}
		}
	}
	// A�� ������ �׵��� �̵���
	for (; As <= Ae; As++)
	{
		attach(termsA[As].coef, termsA[As].expon);
	}
	// B�� ������ �׵��� �̵���
	for (; Bs <= Be; Bs++)
	{
		attach(termsB[Bs].coef, termsB[Bs].expon);
	}
	*Ce = avail - 1; // ���׽� C�� �ִ� ����
}

void print_poly(polynomial *terms, int aE) // ���׽� ����ϴ� �Լ�
{
	for (int i = 0; i < aE; i++)
	{
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon); // �ִ� ���� �ٷ� ������ +���� ���
	}
	printf("%3.1fx^%d\n", terms[aE].coef, terms[aE].expon); // �ִ� ���������� �׸� ���
}

int main(void)
{
	int Ae = 0, Be = 0, Ce = 0; // ���׽� A, B, C�� ������ �ִ� ������ ������ ���� ���� �� �ʱ�ȭ
	printf("���� ���� �� ���׽� A, B�� �Է��Ͻÿ�. (���� �ִ� 10������ �Է°���)\n");
	printf("���׽�A ���� ����� ������ ū �������� ���ʴ�� �Է��Ͻÿ�.\n�� �Է½� \"0 0\"�� �Է��� ����");
	printf(" �Ǵ� 10���� �� �Է½� �ڵ� ����\n");

	for(int t = 0; t < MAX_TERMS; t++) // �迭 ���� 10 0~9����
	{
		//printf("���� �迭��ġ �迭[%d]\n", t);
		printf("���� ��� ���� ���� >>");
		scanf_s("%f %d", &termsA[t].coef, &termsA[t].expon); 
		printf("%3.1fx^%d\n", termsA[t].coef, termsA[t].expon);

		if (termsA[t].coef == 0 || termsA[t].coef == 0 && termsA[t].expon == 0) // ����� 0�� ���� �Է��Ͽ��ų� ��� �� ������ 0�� ���� �Է��� ���
		{
			Ae = t - 1; // ����� �迭�� �ִ� ������ t-1 �� ����
			break; 
		}
		if (t == MAX_TERMS - 1) // t�� �ִ���� �϶�, 10���� �� �Է��� ���
		{
			Ae = t; 
		}
		
		if (termsA[t].expon < 0) // ���� ������ �Է��� ���
		{
			printf("���� ������ �Է��� �� �����ϴ�.\n");
			termsA[t].coef = 0, termsA[t].expon = 0;
			if(t > 0)
			t--;
		}

		if (t >= 1) // 1�϶����� �� ����
		{
			if (compare(termsA[t].expon, termsA[t - 1].expon) == '>') // ���� > ����
			{
				printf("������ ������������ Ů�ϴ�, �ٽ� �Է��ϼ���\n");
				termsA[t].expon = 0, termsA[t].coef = 0; // ���� �Է¹��� ���� 0���� ����
				t--;
			}
			if (compare(termsA[t].expon, termsA[t - 1].expon) == '=') // ���� = ����
			{
				float sum = 0.0;
				sum = termsA[t].coef + termsA[t-1].coef; // ����� ��
				termsA[t -1].coef = sum; // ���� ���� �� ���� ����
				printf("������ ���������� �����ϴ�, ���մϴ�\n���� ");
				printf("%3.1fx^%d\n", termsA[t - 1].coef, termsA[t - 1].expon);
				termsA[t].coef = 0, termsA[t].expon = 0; // ���� ���� 0���� ���� �� �ٽ� t��ġ���� �Է� ����
				t--;
			}
		}
		printf("���� %d���� �� ����\n", t + 1); // ��� ���� ���� �ƴ��� ���
		//printf("�迭[%d]�� ����Ǿ����ϴ�. �ִ����[%d]\n", t, MAX_TERMS - 1);
	}

	printf("------------------------------------------------------------------\n");
	printf("���׽�B ���� ����� ������ ū �������� ���ʴ�� �Է��Ͻÿ�.\n�� �Է½� \"0 0\"�� �Է��� ����");
	printf(" �Ǵ� 10���� �� �Է½� �ڵ� ����\n");

	for (int t = 0; t < MAX_TERMS; t++) 
	{
		//printf("���� �迭��ġ �迭[%d]\n", t);
		printf("���� ��� ���� ���� >>");
		scanf_s("%f %d", &termsB[t].coef, &termsB[t].expon);
		printf("%3.1fx^%d\n", termsB[t].coef, termsB[t].expon);

		if (termsB[t].coef == 0 || termsB[t].coef == 0 && termsB[t].expon == 0)
		{
			Be = t - 1;
			break;
		}
		if (t == MAX_TERMS - 1)
		{
			Be = t;
		}

		if (termsB[t].expon < 0)
		{
			printf("���� ������ �Է��� �� �����ϴ�.\n");
			termsB[t].coef = 0, termsB[t].expon = 0;
			if (t > 0)
			t--;
		}

		if (t >= 1) 
		{
			if (compare(termsB[t].expon, termsB[t - 1].expon) == '>')
			{
				printf("������ ������������ Ů�ϴ�, �ٽ� �Է��ϼ���\n");
				termsB[t].expon = 0, termsB[t].coef = 0;
				t--;
			}
			if (compare(termsB[t].expon, termsB[t - 1].expon) == '=')
			{
				float sum = 0.0;
				sum = termsB[t].coef + termsB[t - 1].coef;
				termsB[t - 1].coef = sum;
				printf("������ ���������� �����ϴ�, ���մϴ�\n���� ");
				printf("%3.1fx^%d\n", termsB[t - 1].coef, termsB[t - 1].expon);
				termsB[t].coef = 0, termsB[t].expon = 0;
				t--;
			}
		}
		printf("���� %d���� �� ����\n", t + 1);
		//printf("�迭[%d]�� ����Ǿ����ϴ�. �ִ����[%d]\n", t, MAX_TERMS - 1);
	}
	printf("\n");

	poly_add2(Ae, Be, &Ce); // ���׽� A, B�� ���ϰ� C�� ����
	print_poly(termsA, Ae); // ���׽� A ���
	print_poly(termsB, Be); // ���׽� B ���
	printf("------------------------------------------------------------------\n");
	print_poly(termsC, Ce); // ���׽� C ���

	return 0;
}