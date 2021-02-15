#include <stdio.h>

// 2021.02.04 20:55

// 풀이 방법 2개
// 1) 문제에서 나온 방식 그대로 구현
// 2) 누적계산을 값*(N-i)번 하는 것 

int main(void) {
	int N, Temp;
	int Time[1001] = {0,};
	int NowTime = 0, MinTime = 0;
	
	scanf("%d", &N);
	
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Temp);
		Time[Temp] = Time[Temp] + 1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Time[i]; j++) {
			NowTime = NowTime + i;
			MinTime = MinTime + NowTime;
			//printf("%d %d\n", NowTime, MinTime);
		}
	}
	
	/*
	// 다른 풀이 
	int Index = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Time[i]; j++) {
			MinTime = MinTime + i*(N-(Index++));
			//printf("%d %d\n", NowTime, MinTime);
		}
	}
	*/
	
	printf("%d\n", MinTime);
	
	return 0;
}
