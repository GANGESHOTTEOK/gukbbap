#include <stdio.h>
#include <limits.h>

// 2021.01.12 23:42

// int 범위 -2,147,483,648 ~ 2,147,483,647

// calc을 다시 돌려줘야 하는 걸 체크 못함. => 해결 
// 다른 사람 풀이가 더 간단함. https://www.acmicpc.net/source/17074528

int NumArr[11], Operator[4];
int N;
int Max = INT_MIN, Min = INT_MAX;
int Calc = 0;
int CheckMaxMin(int Plus, int Minus, int Multiply, int Divide, int Depth) {

	if (Depth == N) {
		if (Calc > Max) {
			Max = Calc;
		}
		if (Calc < Min) {
			Min = Calc;
		}
		return 0;
	}
	
	int Remainder = Calc % NumArr[Depth];
	
	for (int i = 0; i < 4; i++) {
			if (i == 0 && Plus) {
				Calc = Calc + NumArr[Depth];
				CheckMaxMin(Plus-1, Minus, Multiply, Divide, Depth+1);
				Calc = Calc - NumArr[Depth];
			}
			if (i == 1 && Minus) {
				Calc = Calc - NumArr[Depth];
				CheckMaxMin(Plus, Minus-1, Multiply, Divide, Depth+1);
				Calc = Calc + NumArr[Depth];
			}
			if (i == 2 && Multiply) {
				Calc = Calc * NumArr[Depth];
				CheckMaxMin(Plus, Minus, Multiply-1, Divide, Depth+1);
				Calc = Calc / NumArr[Depth];
			}
			if (i == 3 && Divide) {
				Calc = Calc / NumArr[Depth];
				CheckMaxMin(Plus, Minus, Multiply, Divide-1, Depth+1);
				Calc = Calc * NumArr[Depth] + Remainder;
			}
	}
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &NumArr[i]);
	}
	for (int i = 0; i < 4; i++) {
		scanf("%d", &Operator[i]);
	}
	
	Calc = NumArr[0];
	
	CheckMaxMin(Operator[0], Operator[1], Operator[2], Operator[3], 1);
	
	printf("%d\n%d\n", Max, Min);
	
	return 0;
} 
