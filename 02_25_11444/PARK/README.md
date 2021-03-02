# 2021년 02월 25일 목요일
# 백준 11444번 피보나치 수 6
### https://www.acmicpc.net/problem/11444

---
### 문제 해결 날짜 및 시간
- 2021.02.25 21:47

---

### 접근 방식
- 피보나치를 구하는 방법 중 Matrix[2][2] = {{1,1}, {1,0}}를 거듭제곱하는 방법이 있음
- 결국 10830 행렬 제곱에서 초기 행렬의 값이 정해져 있는 문제. 같은 방식으로 풀면 해결
- 행렬을 곱하는 것은 2740 행렬 곱샘 이용, 거듭제곱은 1629 곱셈

---

### 소스코드
- 메모리 : KB
- 시간 : ms
```c
#include <stdio.h>
#define Divisor 1000000007
#define N 2

long long int B;
long long int Matrix[2][2] = {{1,1}, {1,0}}, Power[2][2] = {0,}, Temp[2][2] = {{1,1}, {1,0}};

int InitTemp(void) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			Temp[i][j] = Power[i][j];
		}
	}
	
	return 0;
}

int Multiplication(void) { // 매개변수 변경해서 1개의 함수로 표현 가능 했음
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

int Multiplication2(void) { // 매개변수 변경해서 1개의 함수로 표현 가능 했음
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

	scanf("%lld", &B);
	
	if (B <= 2) { 1, 2 차례 피보나치 수 처리
		printf("%d\n", 1);
		return 0;
	}
	
	MatrixPower(B-1);
	
	printf("%lld\n", Power[0][0]);
	
	return 0;
}

```
