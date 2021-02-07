# 2021년 02월 05일 금요일
# 백준 11047번 [동전 0]
### https://www.acmicpc.net/problem/11047

---

### 문제 해결 날짜 및 시간
- 2021.02.03 19:22

---

### 접근 방식
- 입력된 코인의 값 중 가장 큰 값부터 넣어가며 계산
- 사용한 지폐 개수 : K/Coin[i], 지폐 사용 후 남은 금액 : K = K%Coin[i]

---

### 소스코드
- 1116KB, 0ms

```C
#include <stdio.h>

int main(void) {
	int N, K;
	int Coin[10];
	int MinCoin = 0;
	
	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Coin[i]);
	}
	
	for (int i = N-1; i >= 0; i--) {
		if (K/Coin[i]) {
			MinCoin = MinCoin + K/Coin[i];
			K = K%Coin[i];
		}
	}
	
	printf("%d\n", MinCoin);
	
	return 0;
}
```
