
# 2021년 01월 25일 월요일
# 백준 2579번 [계단 오르기]
### https://www.acmicpc.net/problem/2579

---

### 문제 해결 날짜 및 시간
- 2021.01.21 00:38

---
### 접근방식
- 처음에는 규칙이 있을 거라는 생각으로 접근. 생각한 규칙에 따라 풀이한 결과 반례 존재(memoization 고려 x)
- 좀 더 작은 단위로 생각. memoization을 사용하는 방향으로.
- 경우는 2가지 경우. 011, 01(마지막 계단만 무조건). 두 경우 중 값이 더 큰 경우를 Dp에 저장. 이를 반복

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>

int ReturnBiger(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int N;
	int Stairs[300], Dp[300];

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Stairs[i]);
	}
	
	Dp[0] = Stairs[0];
	
	if (N > 1)
		Dp[1] = Dp[0] + Stairs[1];	
	if (N > 2)
		Dp[2] = ReturnBiger(Stairs[1]+Stairs[2], Stairs[0]+Stairs[2]);
	if (N > 3) {
		for (int i = 3; i < N; i++) {
			Dp[i] = ReturnBiger(Dp[i-3]+Stairs[i-1], Dp[i-2]) + Stairs[i];
		}
	}

	printf("%d\n", Dp[N-1]);
	
	return 0;
}
```
