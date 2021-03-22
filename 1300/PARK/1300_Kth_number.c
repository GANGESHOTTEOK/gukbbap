#include <stdio.h>

int Min(const int a, const int b) {
	return (a < b ? a : b);
}

int main(void) {
	int N, K, Start = 1, End = 0, Ans = 0;
	
	scanf("%d %d", &N, &K);
	
	K = (K > 1000000000) ? 1000000000 : K;
	
	End = K;
	
	while(Start <= End) {
		int Mid = (Start+End)/2;
		int Count = 0;
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int Num = ((i+1)*(j+1));
				if (Num <= Mid)
					Count++;
				else
					break;
			}
		}
		*/
		
		for (int i = 1; i <= N; i++)
			Count = Count + Min(N, Mid/i);
			 // 가장 중요한 부분 
			
		if (Count < K)
			Start = Mid+1;
		else{
			End = Mid-1;
			Ans = Mid;
		}
		
	}
	
	printf("%d\n", Ans);
	
	return 0;
}
