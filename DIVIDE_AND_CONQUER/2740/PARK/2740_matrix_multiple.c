#include <stdio.h>

// 2021.02.23 21:53

int main(void) {
	int N, M, K;
	
	int Matrix1[100][100], Matrix2[100][100], Matrix3[100][100];
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &Matrix1[i][j]);
		}
	}
	
	scanf("%d %d", &M, &K);
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < K; j++) {
			scanf("%d", &Matrix2[i][j]);
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			for (int l = 0; l < M; l++) { // point!!
				Matrix3[i][j] = Matrix3[i][j] + (Matrix1[i][l]*Matrix2[l][j]);
			}
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < K; j++) {
			printf("%d ", Matrix3[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
