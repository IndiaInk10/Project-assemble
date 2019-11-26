#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 10 // 배열의 크기
typedef struct
{
	float coef; // 항의 계수
	int expon; // 항의 차수
} polynomial;

polynomial termsA[MAX_TERMS] = { 0, }, termsB[MAX_TERMS] = { 0, }, termsC[2 * MAX_TERMS] = { 0, }; // 배열을 0으로 초기화
int avail = 0; // 합을 저장할 다항식의 배열의 위치 수 termsC[avail = 0]

// 두 개의 정수 비교
char compare(int a, int b) // int 입력 비교 후 char값 출력
{
	if (a > b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail > 2 * MAX_TERMS) // 다항식 C의 최대 범위, 각 다항식이 만약 차수가 하나도 안 겹칠 시 최대 20개
	{
		fprintf(stderr, "항의 개수가 너무 많음\n"); // 배열의 최대 범위를 넘을 시 에러 표시
		exit(1);
	}
	termsC[avail].coef = coef;
	termsC[avail].expon = expon;
	avail++; // 다음 배열에 입력하기 위해 증가연산
}

// C = A + B
void poly_add2(int Ae, int Be, int *Ce) // 각 배열의 최대범위를 입력받는다, 각 배열이 전역변수이기 때문에  최대범위만 입력받는 것이 가능
{
	float tempcoef = 0.0; // 실수형 변수 선언 및 초기화
	int As = 0, Bs = 0; // 다항식 A, B의 배열의 위치 수를 표현할 변수 선언 및 초기화

	while (As <= Ae && Bs <= Be) // 다항식 A, B 배열 모두 저장된 배열 범위 안에 있을 때 까지 반복
	{
		switch (compare(termsA[As].expon, termsB[Bs].expon))
		{
		case '>': // A의 차수 > B의 차수
		{
			attach(termsA[As].coef, termsA[As].expon); // A의 차수가 더 클 경우 해당 차수의 계수와 차수를 다항식 C에 입력
			As++;	break; // 다항식 A의 다음 배열로 이동 
		}
		case '=': // A의 차수 = B의 차수
		{
			tempcoef = termsA[As].coef + termsB[Bs].coef; // A와 B의 차수가 같을 시 계수를 더해준다
			if (tempcoef) // = if (tempcoef != 0)
			{
				attach(tempcoef, termsA[As].expon); // 더해준 계수를 C에 넣어주고, 차수는 A에서 넣든 B에서 넣든 다 가능
			}
			As++; Bs++; tempcoef = 0.0;  break; // 각 다항식의 배열 다음 위치로
		}
		case '<': // A의 차수 < B의 차수
		{
			attach(termsB[Bs].coef, termsB[Bs].expon); // B의 차수가 더 클 경우 해당 차수의 계수와 차수를 다항식 C에 입력
			Bs++;	break; // 다항식 B의 다음 배열로 이동
		}
		}
	}
	// A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
	{
		attach(termsA[As].coef, termsA[As].expon);
	}
	// B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
	{
		attach(termsB[Bs].coef, termsB[Bs].expon);
	}
	*Ce = avail - 1; // 다항식 C의 최대 범위
}

void print_poly(polynomial *terms, int aE) // 다항식 출력하는 함수
{
	for (int i = 0; i < aE; i++)
	{
		printf("%3.1fx^%d + ", terms[i].coef, terms[i].expon); // 최대 범위 바로 전까진 +까지 출력
	}
	printf("%3.1fx^%d\n", terms[aE].coef, terms[aE].expon); // 최대 범위에서는 항만 출력
}

int main(void)
{
	int Ae = 0, Be = 0, Ce = 0; // 다항식 A, B, C의 각각의 최대 범위를 저장할 변수 선언 및 초기화
	printf("합을 구할 두 다항식 A, B를 입력하시오. (항은 최대 10개까지 입력가능)\n");
	printf("다항식A 항의 계수와 차수를 큰 차수부터 차례대로 입력하시오.\n다 입력시 \"0 0\"를 입력해 종료");
	printf(" 또는 10개를 다 입력시 자동 종료\n");

	for(int t = 0; t < MAX_TERMS; t++) // 배열 생성 10 0~9까지
	{
		//printf("현재 배열위치 배열[%d]\n", t);
		printf("항의 계수 항의 차수 >>");
		scanf_s("%f %d", &termsA[t].coef, &termsA[t].expon); 
		printf("%3.1fx^%d\n", termsA[t].coef, termsA[t].expon);

		if (termsA[t].coef == 0 || termsA[t].coef == 0 && termsA[t].expon == 0) // 계수가 0인 값을 입력하였거나 계수 및 차수가 0인 값을 입력할 경우
		{
			Ae = t - 1; // 저장된 배열의 최대 범위을 t-1 로 저장
			break; 
		}
		if (t == MAX_TERMS - 1) // t가 최대범위 일때, 10개를 다 입력한 경우
		{
			Ae = t; 
		}
		
		if (termsA[t].expon < 0) // 음수 차수를 입력한 경우
		{
			printf("음수 차수는 입력할 수 없습니다.\n");
			termsA[t].coef = 0, termsA[t].expon = 0;
			if(t > 0)
			t--;
		}

		if (t >= 1) // 1일때부터 비교 시작
		{
			if (compare(termsA[t].expon, termsA[t - 1].expon) == '>') // 현재 > 이전
			{
				printf("차수가 이전차수보다 큽니다, 다시 입력하세요\n");
				termsA[t].expon = 0, termsA[t].coef = 0; // 현재 입력받은 값을 0으로 설정
				t--;
			}
			if (compare(termsA[t].expon, termsA[t - 1].expon) == '=') // 현재 = 이전
			{
				float sum = 0.0;
				sum = termsA[t].coef + termsA[t-1].coef; // 계수의 합
				termsA[t -1].coef = sum; // 이전 값에 그 합을 대입
				printf("차수가 이전차수와 같습니다, 더합니다\n다음 ");
				printf("%3.1fx^%d\n", termsA[t - 1].coef, termsA[t - 1].expon);
				termsA[t].coef = 0, termsA[t].expon = 0; // 현재 값은 0으로 설정 후 다시 t위치부터 입력 받음
				t--;
			}
		}
		printf("현재 %d개의 항 저장\n", t + 1); // 몇개의 항이 저장 됐는지 출력
		//printf("배열[%d]에 저장되었습니다. 최대범위[%d]\n", t, MAX_TERMS - 1);
	}

	printf("------------------------------------------------------------------\n");
	printf("다항식B 항의 계수와 차수를 큰 차수부터 차례대로 입력하시오.\n다 입력시 \"0 0\"를 입력해 종료");
	printf(" 또는 10개를 다 입력시 자동 종료\n");

	for (int t = 0; t < MAX_TERMS; t++) 
	{
		//printf("현재 배열위치 배열[%d]\n", t);
		printf("항의 계수 항의 차수 >>");
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
			printf("음수 차수는 입력할 수 없습니다.\n");
			termsB[t].coef = 0, termsB[t].expon = 0;
			if (t > 0)
			t--;
		}

		if (t >= 1) 
		{
			if (compare(termsB[t].expon, termsB[t - 1].expon) == '>')
			{
				printf("차수가 이전차수보다 큽니다, 다시 입력하세요\n");
				termsB[t].expon = 0, termsB[t].coef = 0;
				t--;
			}
			if (compare(termsB[t].expon, termsB[t - 1].expon) == '=')
			{
				float sum = 0.0;
				sum = termsB[t].coef + termsB[t - 1].coef;
				termsB[t - 1].coef = sum;
				printf("차수가 이전차수와 같습니다, 더합니다\n다음 ");
				printf("%3.1fx^%d\n", termsB[t - 1].coef, termsB[t - 1].expon);
				termsB[t].coef = 0, termsB[t].expon = 0;
				t--;
			}
		}
		printf("현재 %d개의 항 저장\n", t + 1);
		//printf("배열[%d]에 저장되었습니다. 최대범위[%d]\n", t, MAX_TERMS - 1);
	}
	printf("\n");

	poly_add2(Ae, Be, &Ce); // 다항식 A, B를 합하고 C에 저장
	print_poly(termsA, Ae); // 다항식 A 출력
	print_poly(termsB, Be); // 다항식 B 출력
	printf("------------------------------------------------------------------\n");
	print_poly(termsC, Ce); // 다항식 C 출력

	return 0;
}