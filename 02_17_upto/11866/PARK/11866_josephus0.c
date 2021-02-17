#include <stdio.h>

// 2021.02.17 20:19

int main(void) {
	int N, K, Front, Back;
	int People[1002] = {0,}, Ans[1002] = {0,};
	
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N+1; i++) {
		People[i] = i;
	}
	
	Front = 1, Back = N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j < K; j++) {
			Back = Back%N + 1;
			People[Back] = People[Front];
			Front = Front%N + 1;
		}
		Ans[i] = People[Front];
		Front = Front%N + 1;
	}
	
	printf("<");
	
	for (int i = 1; i < N; i++)
		printf("%d, ", Ans[i]);
	
	printf("%d>", Ans[N]);
	
	return 0;
}
