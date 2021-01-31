#include <stdio.h>

// 2021.01.21 00:38

// 마지막부터 시작
// 1다음에 무조건 2가 나와야 한다고 생각해서 틀림. 211이 가능함
// 111이 나오는 반례가 존재했음. memoization을 생각하지  않은 결과 
 
// 계속 memoization을 어떻게 할지 생각하기 
// 재귀를 동적계획법으로 풀 수 있는 방법 항상 생각하기 

// 추가 생각 https://www.acmicpc.net/board/view/52508

int ReturnBiger(int a, int b) {
	return (a > b) ? a : b;
}

int main(void) {
	int N;
	int Stairs[300], Dp[300];

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Stairs[i]);
	}
	
	Dp[0] = Stairs[0];
	
	if (N > 1)
		Dp[1] = Dp[0] + Stairs[1];	
	if (N > 2)
		Dp[2] = ReturnBiger(Stairs[1]+Stairs[2], Stairs[0]+Stairs[2]);
	if (N > 3) {
		for (int i = 3; i < N; i++) {
			Dp[i] = ReturnBiger(Dp[i-3]+Stairs[i-1], Dp[i-2]) + Stairs[i];
		}
	}

	printf("%d\n", Dp[N-1]);
	
	return 0;
}
/*35253761
11
1---
6---
4
7---
3--
7 --
5-
2---
1
5---
3---

11
1
6
4
7
3
7
5
2
1
5
3
*/
