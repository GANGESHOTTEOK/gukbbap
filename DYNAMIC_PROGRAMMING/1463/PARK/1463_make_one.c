#include <stdio.h>

// 2021.01.21 01:49

// 애해하기. 훨씬 간단한 코드  https://www.acmicpc.net/source/9193008

int CalcCnt[1000001] = {0,1,1};

int ReturnSmaller(int a, int b) {
	return a <= b ? a : b;
}

int MakeOneCount(int Index) {
	if (Index%3 == 0 && Index%2 == 0)
		return ReturnSmaller(ReturnSmaller(CalcCnt[Index/3-1], CalcCnt[Index-2]), CalcCnt[Index/2-1])+1;
	else if (Index%3 == 0)
		return ReturnSmaller(CalcCnt[Index/3-1], CalcCnt[Index-2])+1;
	else if (Index%2 == 0)
		return ReturnSmaller(CalcCnt[Index/2-1], CalcCnt[Index-2])+1;
	else
		return CalcCnt[Index-2]+1;
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 3; i < N; i++) {
		CalcCnt[i] = MakeOneCount(i+1);
	}
	
	printf("%d\n", CalcCnt[N-1]);
	
	return 0;
}

/*
642 10
643 11
*/
