#include <stdio.h>

// 2021.02.16 23:30

// 배열 없이 풀어보기 

int Queue[1000001];

int main(void) {
	int N, End;
	
	scanf("%d", &N);
	
	End = N-1;
	
	for (int i = 0; i <= End; i++) {
		if (i < N)
			Queue[i] = i+1;
		if ((i&1))
			Queue[++End] = Queue[i];
	}
	
	if (N==1)
		printf("1\n");
	else
		printf("%d", Queue[End-1]);
	
	
	return 0;
}
