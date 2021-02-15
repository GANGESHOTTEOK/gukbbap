# 2021년 02월 10일 수요일
# 백준 13305번 주유소
### https://www.acmicpc.net/problem/13305

---

### 문제 해결 날짜 및 시간
- 2021.02.07 21:40

---

### 접근방식
- 기름의 가격이 낮을 수록 좋으니까 매 주유소마다 MinGas를 갱신해서 거리만큼 곱하기

---

### 소스코드
- 2560KB, 40ms

```C
#include <stdio.h>

long long int Distance[100001] = {0,}, Gas[100001] = {0,};

int main(void) {
	int N, PreGas;
	long long int MinCost = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N-1; i++)
		scanf("%d", &Distance[i]);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Gas[i]);
	
	PreGas = Gas[0];
	for (int i = 0; i < N; i++) {
		PreGas = PreGas < Gas[i] ? PreGas : Gas[i];
		MinCost = MinCost + (PreGas * Distance[i]);
	}
	
	printf("%lld\n", MinCost);
	
	return 0;
}
```
