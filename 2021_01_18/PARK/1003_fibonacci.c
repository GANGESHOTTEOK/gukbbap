#include <stdio.h>

// 2021.01.13 23:07

// 이미 실행한 적 있는 과정을 다시 반복하여 중복연산을 만드는 것 대신에
// 메모이제이션(memoization)이라는 방법을 사용해서 이전 데이터를  저장해두는 것
// 재귀로 구현하는 부분 참고하기 https://blog.naver.com/kks227/220777103650
// 추가 참고  https://url.vet/wn5qj

int FiboArr[41];

int main(void) {
	int T, N;
	
	scanf("%d", &T);
	
	FiboArr[0] = 0;
	FiboArr[1] = 1;
	
	for (int i = 2; i < 41; i++) {
		FiboArr[i] = FiboArr[i-1] + FiboArr[i-2];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N == 0)
			printf("%d %d\n", 1, 0);
		else
			printf("%d %d\n", FiboArr[N-1], FiboArr[N]);
	}

	return 0;
}
