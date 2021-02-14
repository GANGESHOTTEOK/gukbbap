#include <stdio.h>

// 2021.02.07 21:40

long long int Distance[100001] = {0,}, Gas[100001] = {0,};

int main(void) {
	int N, PreGas;
	long long int MinCost = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N-1; i++)
		scanf("%d", &Distance[i]);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Gas[i]);
	
	PreGas = Gas[0];
	for (int i = 0; i < N; i++) {
		PreGas = PreGas < Gas[i] ? PreGas : Gas[i];
		MinCost = MinCost + (PreGas * Distance[i]);
	}
	
	printf("%lld\n", MinCost);
	
	return 0;
}
