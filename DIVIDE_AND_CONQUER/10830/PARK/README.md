# 2021년 02월 24일 수요일
# 백준 10830번 행렬 제곱
### https://www.acmicpc.net/problem/10830

---
### 문제 해결 날짜 및 시간
- 2021.02.24 22:05

---

### 접근 방식
- 행렬 곱셈에 이은 행렬 제곱 문제
- 1629 곱셈 + 2740 행렬 곱셈 = 10830 행렬 제곱
- 곱셈 과정은 2740 행렬 곱셈과 동일, 거듭제곱 과정은 1629 곱셈과 동일

---

### 소스코드
- 메모리 : 1116KB
- 시간 : 0ms
```c
#include <stdio.h>
#define Divisor 1000

// Power[i][j] = Power[i][j] + ((Temp[i][l]*Matrix[l][j]) % Divisor);
// 계속 이전 계산값을 갈아 치우는 것이 아니라 더하기를 해서 값이 이상했던 것
// 이 부분 수정 후 정답 
 
int N;
long long int B;
long long int Matrix[6][6], Power[6][6] = {0,}, Temp[6][6] = {0,};

int InitTemp(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Temp[i][j] = Power[i][j];
		}
	}
	
	return 0;
}

int Multiplication(void) { // 리팩토링 가능
	long long int Trash = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Trash = 0;
			for (int l = 0; l < N; l++) // point!!
				Trash += (Temp[i][l]*Temp[l][j]) % Divisor;
			Power[i][j] = Trash % Divisor;
		}
	}
	return 0;
}

int Multiplication2(void) { // 리팩토링 가능
	long long int Trash = 0;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Trash = 0;
			for (int l = 0; l < N; l++) // point!!
				Trash += (Temp[i][l]*Matrix[l][j]) % Divisor;
			Power[i][j] = Trash % Divisor;
		}
	}
	return 0;
}

int MatrixPower(long long int Repeat) {
	
	if (Repeat <= 1)
		return 1;
	
	MatrixPower(Repeat/2);

	Multiplication();
	InitTemp();
	
	if (Repeat&1) {
		Multiplication2();
		InitTemp();
	}
	
	return 0;
}

int main(void) {

	scanf("%d %lld", &N, &B);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &Matrix[i][j]);
			Temp[i][j] = Matrix[i][j];
			Power[i][j] = Matrix[i][j] % Divisor;
		}
	}
	
	MatrixPower(B);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%d ", Power[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
```
