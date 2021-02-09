#include <stdio.h>

// 2021.02.03 19:22

int main(void) {
	int N, K;
	int Coin[10];
	int MinCoin = 0;
	
	scanf("%d %d", &N, &K);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Coin[i]);
	}
	
	for (int i = N-1; i >= 0; i--) {
		if (K/Coin[i]) {
			MinCoin = MinCoin + K/Coin[i];
			K = K%Coin[i];
		}
	}
	
	printf("%d\n", MinCoin);
	
	return 0;
}
