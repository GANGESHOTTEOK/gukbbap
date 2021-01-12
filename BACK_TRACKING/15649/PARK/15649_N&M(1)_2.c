#include <stdio.h>

// 2021.01.10 20:40

int N, M;
int Sequence[8], Visited[9]; // char로 구현 시 더 빠름
// 수열 배열과 방문 여부 체크 배열 

int BackTracking (int NowDepth) { // 현재 깊이(몇 번째 재귀 중인지)
	if (NowDepth == M) { // M번 뽑았다면 
		for (int i = 0; i < M; i++) {
			printf("%d ", Sequence[i]); // 출력
		}
		printf("\n");
		return 0;
	}
	for (int j = 1; j <= N; j++) {
		if (!Visited[j]) { // 방문하지 않았다면 
			Visited[j] = 1; // 이제 방문으로 
			Sequence[NowDepth] = j; // 현재 몇번째 이고 값이 무엇인지
			BackTracking(NowDepth+1); // 재귀
			Visited[j] = 0; // 다음 경우의 수를 위한 미방문
		}
	}
	return 0;
}

int main(void) {
	
	scanf("%d %d", &N, &M);
	
	BackTracking(0);
	
	return 0;
} 
