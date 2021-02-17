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
