
# 2021년 01월 13일 수요일
# 백준 9663번 [N-Queen]
### https://www.acmicpc.net/problem/15652

---

### 문제 해결 날짜 및 시간
- 2021.01.11 23:12

---

### 접근 방식
- 체스 판(2차원 배열)을 사용하여 1, 0으로 둘 수 있는 곳을 표시하여 구현했지만 => 시간초과
- 퀸의 위치를 데이터로 하는 배열을 선언(index가 x, value가 y)하여 그 배열과 현재 두려고 하는 위치를 가로, 세로, 대각선으로 비교

---

### 소스코드
- 1116KB, 4600ms

```C
#include <stdio.h>
#include <stdlib.h>

// 2021.01.11 11:12

// 방문여부 확인 2차원 배열을 만들었지만 => 시간초과 
// index를 x로 value를 y로 잡고 퀸 배열을 만들고 비교

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
```
