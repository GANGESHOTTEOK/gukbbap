# 2021년 02월 08일 월요일
# 백준 11399번 ATM
### https://www.acmicpc.net/problem/11399

---

### 문제 해결 날짜 및 시간
- 2021.02.4 20:55

---

### 접근방식
- 누적 합이라서 작은 수를 앞에서 부터 더해야 최솟값을 구할 수 있는 문제
- 1) 카운팅 배열 사용, 문제 나온 방식 그대로 구현
- 2) 누적합의 특성을 이용해서 값*(N-i)를 하는 것

---

### 소스코드
- 1116KB, 0ms

```C
#include <stdio.h>

// 풀이 방법 2개
// 1) 문제에서 나온 방식 그대로 구현
// 2) 누적계산을 값*(N-i)번 하는 것 

int main(void) {
	int N, Temp;
	int Time[1001] = {0,};
	int NowTime = 0, MinTime = 0;
	
	scanf("%d", &N);
	
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Temp);
		Time[Temp] = Time[Temp] + 1;
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Time[i]; j++) {
			NowTime = NowTime + i;
			MinTime = MinTime + NowTime;
		}
	}
	
	/*
	// 다른 풀이 
	int Index = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < Time[i]; j++) {
			MinTime = MinTime + i*(N-(Index++));
		}
	}
	*/
	
	printf("%d\n", MinTime);
	
	return 0;
}
```
