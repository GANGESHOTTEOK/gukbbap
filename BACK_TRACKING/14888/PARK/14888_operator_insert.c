#include <stdio.h>
#include <limits.h>

// 2021.01.12 23:42

// int 범위 -2,147,483,648 ~ 2,147,483,647

// calc을 다시 돌려줘야 하는 걸 체크 못함. => 해결 
// 다른 사람 풀이가 더 간단함. https://www.acmicpc.net/source/17074528

// 2021.01.17 18:42.
// 다시보니 굳이 CheckMaxMin에 5개의 para라 필요없었음(Depth와 Calc만 있어도 충분)
// Operator의 value를 빼주고 아니면 더해주고
// 매개변수 선정의 중요성. 훨씬 간결하고 깔끔한 코드를 만들 수 있음 

int NumArr[11], Operator[4];
int N;
int Max = INT_MIN, Min = INT_MAX;
int Calc = 0;
int CheckMaxMin(int Plus, int Minus, int Multiply, int Divide, int Depth) {

	if (Depth == N) { // 모든 연산을 끝냈다면
		if (Calc > Max) { // 계산값이 현재 MAX보다 크다면 
			Max = Calc;
		}
		if (Calc < Min) { // 계산값이 현재 MIN보다 작다면 
			Min = Calc;
		}
		return 0;
	}
	
	int Remainder = Calc % NumArr[Depth]; // 나누었을 때의 값이 올바르지 않을 때 다시 더해주기위해 
	
	for (int i = 0; i < 4; i++) {
		if (i == 0 && Plus) { // 더하기 차례이고 해당 값이  있다면
			Calc = Calc + NumArr[Depth];
			CheckMaxMin(Plus-1, Minus, Multiply, Divide, Depth+1);
			Calc = Calc - NumArr[Depth];
		}
		if (i == 1 && Minus) { // 빼기 차례이고 해당 값이 있다면
			Calc = Calc - NumArr[Depth];
			CheckMaxMin(Plus, Minus-1, Multiply, Divide, Depth+1);
			Calc = Calc + NumArr[Depth];
		}
		if (i == 2 && Multiply) { // 곱하기 차례이고 해당 값이 있다면
			Calc = Calc * NumArr[Depth];
			CheckMaxMin(Plus, Minus, Multiply-1, Divide, Depth+1);
			Calc = Calc / NumArr[Depth];
		}
		if (i == 3 && Divide) { // 나누기 차례이고 해당 값이 있다면
			Calc = Calc / NumArr[Depth];
			CheckMaxMin(Plus, Minus, Multiply, Divide-1, Depth+1);
			Calc = Calc * NumArr[Depth] + Remainder;
		}
	}
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) { // 수 저장 
		scanf("%d", &NumArr[i]);
	}
	for (int i = 0; i < 4; i++) { // 연산자 저장 
		scanf("%d", &Operator[i]);
	}
	
	Calc = NumArr[0];
	
	CheckMaxMin(Operator[0], Operator[1], Operator[2], Operator[3], 1);
	
	printf("%d\n%d\n", Max, Min);
	
	return 0;
} 
