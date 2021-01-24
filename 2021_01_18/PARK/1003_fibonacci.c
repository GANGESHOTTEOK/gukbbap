#include <stdio.h>

// 2021.01.13 23:07

// 이미 실행한 적 있는 과정을 다시 반복하여 중복연산을 만드는 것 대신에
// 메모이제이션(memoization)이라는 방법을 사용해서 이전 데이터를  저장해두는 것
// 재귀로 구현하는 부분 참고하기 https://blog.naver.com/kks227/220777103650
// 추가 참고  https://url.vet/wn5qj

int FiboArr[41]; // N은 0~40 

int main(void) {
	int T, N;
	
	scanf("%d", &T);
	
	FiboArr[0] = 0;
	FiboArr[1] = 1; // 초기 초기화 값 
	
	for (int i = 2; i < 41; i++) { // 피보나치 수열 생성 
		FiboArr[i] = FiboArr[i-1] + FiboArr[i-2];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N == 0)
			printf("%d %d\n", 1, 0);
		else
			printf("%d %d\n", FiboArr[N-1], FiboArr[N]);
	}
	
	// 피보나치 수열의 0을 리턴하는 횟수, 1을 리턴하는 횟우에 대한 집합은
	// 계산하면 {1,0,1,1,2,3,5...}, {0,1,1,2,3,5,8...}
	// 피보나치를 따른다는 것을 알 수 있다. 
	
	return 0;
}
