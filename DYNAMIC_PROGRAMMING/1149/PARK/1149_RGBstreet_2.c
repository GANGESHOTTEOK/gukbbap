#include<stdio.h>
#include<limits.h>

// 2021.01.18 23:24
// 우효 - 토끼탈

// i가 아니면서 최소
// 재귀 

// 컬러의 비용이 같을 떄 오류날 수 있음 // 아래 코드가 그럼 // 2번째 풀이 역시 오류동일
// 처음 3개 -> 2개 중 작은 거 1개 
// 시작을 어디에서 하느냐에 따라 다름

// memoization을 어떻게 사용할지 계속 생각해보기. 
// 백트래킹으로도 풀 수 있을 듯

// 사고의 전환
// 이전에 사용한 색 외 2개 중 비용이 작은 것을 택하는 것이 아닌
// 이미 계산된 비용 2개 중 작은 비용과 지금 Cost를 더하는 방식

int Temp[3], ColorArr[3], CostArr[3] = {0,};

int ReturnMin(int a, int b) {
	return (a < b) ? a : b;
} 

int main(void) {
	int N, MinCost = INT_MAX;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d %d", &ColorArr[0], &ColorArr[1], &ColorArr[2]);
		
		Temp[0] = Temp[0] + ReturnMin(CostArr[1], CostArr[2]) + ColorArr[0];
		Temp[1] = Temp[1] + ReturnMin(CostArr[0], CostArr[2]) + ColorArr[1];
		Temp[2] = Temp[2] + ReturnMin(CostArr[0], CostArr[1]) + ColorArr[2];
		
		for (int j = 0; j < 3; j++) {
			CostArr[j] = Temp[j];
			Temp[j] = 0;
		}
	}
	
	for(int i = 0; i < 3; i++) {
		if (CostArr[i] < MinCost)
			MinCost = CostArr[i];
	}
	
	printf("%d\n", MinCost);
	
	return 0;
}
/*
3
1 2 3
1 2 3
100 1 100
3
1 9 1
3 1 2
9 1 9
3
26 40 83
49 60 57
13 89 99
2 
101 100 101
100 1 100 
3
1 20 30
50 5 6
9 3 7
3 
2 1 3
2 1 5
5 4 3
3 
1 2 2
2 1 2
2 1 2
*/
