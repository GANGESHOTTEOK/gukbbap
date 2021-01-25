#include<stdio.h>

// 2021.01.17 21:31

// 동적 계획법 문제는 memoization의 수 범위도 체크하는 것이 중요

// 새로 알게 된 내용
// 배열 초기화 할 때 a[10] = {1,1}. 이면 11********이 되는 것 

// 파도반 수열이 어떤 규칙을 가지고 있는지 ([i] = [i-1] + [i-5]) 파악하면 쉬운 문제   

int main(void) {
	int T, N;
	long long int PadovanSequence[100] = {1, 1, 1, 2, 2};
	
	scanf("%d", &T);
	
	for (int i = 5; i < 100; i++) {
		PadovanSequence[i] = PadovanSequence[i-5] + PadovanSequence[i-1];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", PadovanSequence[N-1]);
	}
	
	return 0;
} 
