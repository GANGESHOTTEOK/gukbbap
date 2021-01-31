#include <stdio.h>
#define Divisor 1000000000

// 2021.01.23 00:21
// IKON - All The World

// 손 계산 잘못해서 잘못 품
// 9에  

// memoization을 위한 배열을 어떻게 구성할지 고민하기 

// 1149_RGB_street처럼 1차워 배열만 선언해서 풀이 가능 

// 다른 풀이. 간단하고 한번에 이해가능 https://www.acmicpc.net/source/4586941

int main(void) {
	int N;
	long long StairsNum[100][10] = {0};
	long long Ans = 0;
	
	scanf("%d", &N);
	
	for (int i = 1; i < 10; i++) {
		StairsNum[0][i] = 1;
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < 10; j++) {
			if (j == 0)
				StairsNum[i][j] = StairsNum[i-1][j+1] % Divisor;
			else if (j == 9)
				StairsNum[i][j] = StairsNum[i-1][j-1] % Divisor;
			else
				StairsNum[i][j] = (StairsNum[i-1][j-1] + StairsNum[i-1][j+1]) % Divisor;
		}
	}
	
	for (int i = 0; i < 10; i++) {
		Ans = (Ans + StairsNum[N-1][i]) % Divisor;
	}
	
	printf("%lld\n", Ans% Divisor);
	
	return 0;
}
//100 18404112
