#include <stdio.h>

// 2021.01.30 00:22

int main(void) {
	int N, Num;
	int MaxSum = -1001, Temp = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Num);
		if (Temp >= 0)
			Temp = Temp + Num;
		else
			Temp = Num;
		MaxSum = MaxSum > Temp ? MaxSum : Temp;
	}
	
	printf("%d\n", MaxSum);
	
	return 0;
}
