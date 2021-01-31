
# 2021년 01월 28일 목요일
# 백준 2156번 [포도주 시식]
### https://www.acmicpc.net/problem/2156

---

### 문제 해결 날짜 및 시간
- 2021.01.23 09:59

---
### 접근방식
- 2579 계단 오르기 문제와 비슷. 다른 점은 마지막을 먹어야 한다, 아니다 차이
- 그렇다면 경우의 수는 마지막을 먹는 경우(|011, |01)와 먹지 않는 경우(|011|0)
- 이 3가지의 경우 중 가장 큰 값을 DP(WineMax)에 저장하고 계속 활용

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>

int ReturnBiger(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N;
	int Wine[10000];
	int WineMax[10000] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Wine[i]);
		if (i == 0)
			WineMax[i] = Wine[i];
		else
			WineMax[i] = WineMax[i-1] + Wine[i];
		// 모두 다 먹는 상태로 DP(WineMax) 
	}
	
	if (N > 2) { //101, 011, 110
		WineMax[2] = ReturnBiger(ReturnBiger(WineMax[2]-Wine[0], WineMax[2]-Wine[1]), WineMax[2]-Wine[2]);
	}
	if (N > 3) { // 011, 01, 0
		for(int i = 3; i < N; i++) {
			WineMax[i] = ReturnBiger(WineMax[i-1], ReturnBiger(WineMax[i-3]+Wine[i-1], WineMax[i-2])+Wine[i]);
		}
	}
	
	
	printf("%d", WineMax[N-1]);
	
	return 0;
```
