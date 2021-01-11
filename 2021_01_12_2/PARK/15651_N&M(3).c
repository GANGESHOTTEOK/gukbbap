#include <stdio.h>

// 2021.01.10 23:21

int N, M;
int Sequence[8]; // char로 구현 시 더 빠름

int BackTracking (int NowDepth) {
	if (NowDepth == M) {
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]);
		}
		printf("\n");
		return 0;
	}
	for (int j = 1; j <= N; j++) { // 중복 허용. 방문 여부 체크 필요 없음
			Sequence[NowDepth] = j;
			BackTracking(NowDepth+1);
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(0);
	
	return 0;
} 
