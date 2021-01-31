
# 2021년 01월 27일 수요일
# 백준 10844번 [쉬운 계단 수]
### https://www.acmicpc.net/problem/10844

---

### 문제 해결 날짜 및 시간
- 2021.01.23 00:21

---
### 접근방식
- 계단 수는 각 자리수에서 바로 앞자리 수에 -1, +1을 하여 만들 수 있다
- ex) 2자리로 가정하면 10,12(1-1 = 0, 1+1 = 2), 21,23(2-1 = 1, 2+1 = 3) 쭉쭉
- 여기서 주의 할 점은 바로 앞자리 수가 0이나 9일 때는 나올 수 있는 계단 수가 1개라는 점이다.
- 위의 과정을 1의 자리수부터 계속 해보면 트리 구조처럼 나온다.
- 이걸 DP로 표현하면 0일 때는 StairsNum[i-1][j+1], 9일 때는 StairsNum[i-1][j-1]
- 그 외는 StairsNum[i-1][j-1] + StairsNum[i-1][j+1]

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>
#define Divisor 1000000000

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
			if (j == 0) // 0일 때는 +1
				StairsNum[i][j] = StairsNum[i-1][j+1] % Divisor;
			else if (j == 9) // 9일 때는 -1
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
```
