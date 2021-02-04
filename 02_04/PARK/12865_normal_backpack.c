#include <stdio.h>

// 2021.02.02 21:48

// 아직도 memoization을 사용하는데 어려운 듯
// 배열을 어떻게 정의할지, 그리고 어떤 점화식을 가지는지 알아내는데 부족함

// 어딘가 생각이 더이상 전개가 되지 않는 부분이 있는데 그 부분을 해결할 방법 찾기
// 생각이 멈추는 부분 적어두기 

// DP를 1차원으로 할 떄 정방향이 아닌 역방향으로 해야하는 이유는
// 정방향으로 하면 앞에서 미리 계산된 값을 그대로 중복으로 사용할 수도 있음
// 무게가 7이고 가치가 10인 물건일 때 3에서 10이 들어 있으면 10일 때 Pack[3]+10이 되는 것
// 그러면 20이 되니까 원래 기대했던 10이라는 값이 되지 않는 것 

// 1차원 배열로 만들어 보기 

int Backpack[101][100001] = {0,};

int Max(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N, K, Index;
	int Weight[101], Value[101];
	
	scanf("%d %d", &N, &K);
	
	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &Weight[i], &Value[i]);
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= K; j++) {
			if (j - Weight[i] >= 0)
				Backpack[i][j] = Max(Backpack[i-1][j-Weight[i]]+Value[i], Backpack[i-1][j]);
			else
				Backpack[i][j] = Backpack[i-1][j];
		}
	}
	
	printf("%d\n", Backpack[N][K]);
	
	return 0;
}
