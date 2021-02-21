# 백준 17298번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.16 17:51

---

### 접근 방식
- 

### 소스코드
- 메모리 : 12836KB
- 시간 : 324ms
```C
#include <stdio.h>

// 2021.02.16 17:51

// pop, push를 따로 함수로 만들었을 때 시간 줄어듬 

int Arr[1000001], Stack[1000001], NGE[1000001];
int Top = -1;

void Pop(void) {
	Top = Top - 1;
}

void Push(int a) {
	Stack[++Top] = a;
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	for (int i = N-1; i >= 0; i--) {
		while(Top != -1 && Arr[i] >= Stack[Top])
			Pop();
		if (Top == -1)
			NGE[i] = -1;
		else
			NGE[i] = Stack[Top];
		Push(Arr[i]);
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", NGE[i]);
	
	return 0;
}
```
```C
#include <stdio.h>

// 2021.02.16 17:39

// °¡Àå ºü¸¥ ÄÚµå 

int Arr[1000001], Stack[1000001], NGE[1000001];

int main(void) {
	int N, NowNGE = 0, Index = 0, Top = -1;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	for (int i = N-1; i >= 0; i--) {
		if (Top == -1)
			NGE[i] = -1;
		else if (Arr[i] < Stack[Top])
			NGE[i] = Stack[Top];
		else if (Arr[i] >= Stack[Top]) {
			while(Top != -1 && Arr[i] >= Stack[Top])
				Top = Top - 1;
			if (Top == -1)
				NGE[i] = -1;
			else
				NGE[i] = Stack[Top];
		}
		Stack[++Top] = Arr[i];
	}
	
	for (int i = 0; i < N; i++)
		printf("%d ", NGE[i]);
	
	return 0;
}
```