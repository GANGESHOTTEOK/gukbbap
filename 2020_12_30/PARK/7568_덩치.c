#include <stdio.h>

// 2020.12.28 21:11

int main(void) {
	int n = 0, rank = 0;
	int info[50][2] = {0,};
	
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &info[i][1], &info[i][2]);
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (info[j][1] > info[i][1] && info[j][2] > info[i][2]) {
				rank = rank + 1;
			}
		}
		printf("%d ", rank+1);
		rank = 0;
	}
	
	return 0;
}

