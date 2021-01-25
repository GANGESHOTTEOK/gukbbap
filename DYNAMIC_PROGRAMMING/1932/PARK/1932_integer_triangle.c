#include <stdio.h>

// 2021.01.19 21:37
// BIBI - Pretty Ting

// 1차원 배열로 해보기. 

int Triangle[500][500];

int ReturnBiger(int a, int b) {
	return (a > b) ? a : b;
} 

int main(void) {
	int N, Max = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			scanf("%d", &Triangle[i][j]);
		}
	}
	
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i+1; j++) {
			if (j == 0)
				Triangle[i][j] = Triangle[i][j] + Triangle[i-1][j];
			else if (j == i)
				Triangle[i][j] = Triangle[i][j] + Triangle[i-1][j-1];
			else {
				Triangle[i][j] = Triangle[i][j] + ReturnBiger(Triangle[i-1][j-1], Triangle[i-1][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		if(Triangle[N-1][i] > Max)
			Max = Triangle[N-1][i];
	}
	
	printf("%d\n", Max);
	return 0;
}
