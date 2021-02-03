#include <stdio.h>

// 2021.01.29 23:33

int ReturnBiger(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N, Num;
	int MaxSum = -1001, Temp = -1001;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Num);
		Temp = ReturnBiger(Temp+Num, Num);
		MaxSum = ReturnBiger(MaxSum, Temp);
	}

	printf("%d\n", MaxSum);
	
	return 0;
}
