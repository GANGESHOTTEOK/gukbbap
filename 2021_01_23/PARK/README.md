
# 2021년 01월 23일 토요일
# 백준 1932번 [정수 삼각형]
### https://www.acmicpc.net/problem/1932
---

### 문제 해결 날짜 및 시간
- 2021.01.19 21:37

---

### 접근 방식
- RGB문제와 비슷하게 계산한 값과 현재 값을 더하는 방식
- 그런데 삼각형이라서 각 줄의 첫번째와 마지막은 바로 더할 수 있지만
- 그 외는 2개의 값 중 더 큰 값과 더해야 한다

---

### 소스코드
- 2092KB, 16ms
```C
#include <stdio.h>

// 1차원 배열로 해보기. 

int Triangle[500][500];

int ReturnBiger(int a, int b) {
	return (a > b) ? a : b;
} 

int main(void) {
	int N, Max = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			scanf("%d", &Triangle[i][j]);
		}
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0)
				Triangle[i][j] = Triangle[i][j] + Triangle[i-1][j];
			else if (j == i)
				Triangle[i][j] = Triangle[i][j] + Triangle[i-1][j-1];
			else {
				Triangle[i][j] = Triangle[i][j] + ReturnBiger(Triangle[i-1][j-1], Triangle[i-1][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		if(Triangle[N-1][i] > Max)
			Max = Triangle[N-1][i];
	}
	
	printf("%d\n", Max);
	return 0;
}
```
