#include <stdio.h>

// 2021.02.16 17:39

// 가장 빠른 코드 

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
