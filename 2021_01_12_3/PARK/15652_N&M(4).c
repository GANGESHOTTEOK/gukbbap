#include <stdio.h>

// 2021.01.10 23:30

int N, M;
int Sequence[8];// char로 구현 시 더 빠름

int BackTracking (int StartValue, int NowDepth) {
	if (NowDepth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);
		}
		printf("\n");
		return 0;
	}
	for (int j = 1; j <= N; j++) { // 중복 허용. 방문여부 체크 필요 없고 
		if (StartValue <= j) { // 비내림차순을 위한 조건
			Sequence[NowDepth] = j;
			BackTracking(j, NowDepth+1);
		}
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(1, 0);
	
	return 0;
} 
