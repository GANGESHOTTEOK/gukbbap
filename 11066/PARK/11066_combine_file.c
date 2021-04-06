#include <stdio.h>
#include <limits.h>

// 2021.04.06 17:09
// 1980KB, 156ms 

int Min(int a, int b) {
	if (a <= b)
		return a;
	else
		return b;
}

int main(void) {
	int T, K;
	int Cost[501];
	int CostSum[501] = {0,};
	int MinCostSum[501][501] = {0,};
	
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &K);
		for (int j = 0; j < K; j++) {
			scanf("%d", &Cost[j]);
			if (j>0)
				CostSum[j] = CostSum[j-1] + Cost[j];
			else
				CostSum[j] = Cost[j];
		}
		
		for (int Gab = 1; Gab < K; Gab++) {
			for (int Start = 0; Start + Gab < K; Start++) {
				int End = Start + Gab;
				MinCostSum[Start][End] = INT_MAX;
				
				for (int Mid = Start; Mid < End; Mid++) {
					int RangeSum = CostSum[End]-CostSum[Start]+Cost[Start];
					int dpSum = MinCostSum[Start][Mid]+MinCostSum[Mid+1][End];
					
					MinCostSum[Start][End] = Min(MinCostSum[Start][End], dpSum+RangeSum);
				}
			}
		}
		printf("%d\n", MinCostSum[0][K-1]);
	}
	
	return 0;
} 
