#include <stdio.h>

// 2021.03.19 22:25
// 5020KB 228ms

int Tree[1000001];

int main(void) {
	int N, M, LongestSaw = 0, Start = 0, End = 0;
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Tree[i]);
		End = Tree[i] > End ? Tree[i] : End; // End를 가지기 위한 비교 
	}
	
	while(Start <= End) { // 톱에 대한 이분탐색 
		int Mid = (Start + End)/2;
		long long Sum = 0;
		
		for(int i = 0; i < N; i++) {
			if (Tree[i] > Mid)
				Sum = Sum + (Tree[i]-Mid); // 자른 부분의 
		}

		if (Sum >= M) {
			Start = Mid + 1;
			LongestSaw = (Mid > LongestSaw) ? Mid : LongestSaw; // 최대 톱 길이 갱신 
		}
		else
			End = Mid-1;
	}
	
	printf("%d\n", LongestSaw);
	
	return 0;
}
