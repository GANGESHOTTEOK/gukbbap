#include <stdio.h>
#include <stdlib.h>

// 2021.01.11 11:12

// 방문여부 확인 2차원 배열을 만들었지만 => 시간초과 
// index를 x로 value를 y로 잡고 퀸 배열을 만들고 비교

// 다른 사람 코드 참고 해보기 
// https://www.acmicpc.net/source/21665771 
// https://www.acmicpc.net/source/2802464

int N, Count = 0;
int QueenPlace[16];

int CheckPlace (int x, int y) {
	for (int i = 0; i < x; i++) { // 퀸의 위치가 저장된 배열과 현재 넣으려는 위치 비교 
		if (QueenPlace[i] == y || abs(x-i) == abs(QueenPlace[i]-y)) {
			return 0;
		}
		// 가로, 세로, 대각선 비교 
	}
	return 1;
}

int NumberOfCases (int NowDepth) {
	
	if (NowDepth == N) {
		Count = Count + 1;
		return 0;
	}
	
	for (int i = 0; i < N; i++) {
		QueenPlace[NowDepth] = i; // 퀸의 위치를 배열에 삽입 
		if (CheckPlace(NowDepth, i)) { // 둘 수 있는 곳인지 확인 
			NumberOfCases(NowDepth + 1);
		}
	}
	
}

int main(void) {
	
	scanf("%d", &N);
	
	NumberOfCases(0);
	
	printf("%d\n", Count);
		
	return 0;
}
