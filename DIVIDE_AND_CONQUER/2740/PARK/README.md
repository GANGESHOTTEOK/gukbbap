# 2021년 02월 24일 수요일
# 백준 2740번 행렬 곱셈
### https://www.acmicpc.net/problem/2740

---
### 문제 해결 날짜 및 시간
- 2021.02.23 21:53

---

### 접근 방식
- 3중 for문과 배열 3개를 사용해서 행렬1과 행렬2의 곱셈 결과를 행렬3에 저장하는 방식

---

### 소스코드
- 메모리 : 1116KB
- 시간 : 4ms
```c
#include <stdio.h>

int main(void) {
	int N, M, K;
	
	int Matrix1[100][100], Matrix2[100][100], Matrix3[100][100];
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) { // 리팩토링 가능. 함수 선언 했으면 중복할 필요 없었음
		for (int j = 0; j < M; j++) {
			scanf("%d", &Matrix1[i][j]);
		}
	}
	
	scanf("%d %d", &M, &K);
	
	for (int i = 0; i < M; i++) { // 리팩토링 가능. 함수 선언 했으면 중복할 필요 없었음
		for (int j = 0; j < K; j++) {
			scanf("%d", &Matrix2[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int l = 0; l < M; l++) { // point!!
				Matrix3[i][j] = Matrix3[i][j] + (Matrix1[i][l]*Matrix2[l][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("%d ", Matrix3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
```
