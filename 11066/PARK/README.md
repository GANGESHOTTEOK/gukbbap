
# 백준 11066번 문제
https://www.acmicpc.net/problem/11066
---

### 문제 해결 날짜 및 시간

- 2021.04.06 17:09
---

### 접근 방식
- Start와 End 구간에서 최소비용을 저장할 2차원 배열, 비용을 입력 받을 배열, 마지막에 더할 총 구간 합계 배열을 선언
- 구간의 길이(0 < Gap < k) 반복문과 이 구간을 순회할 반복문, 최소합을 DP에 저장할 반복문 이렇게 3중 for문 필요
- 구간의 어느 지점 Mid를 기준으로 이전에 저장된 DP(Start~Mid), DP(Mid+1~End)의 합과 총 구간의 비용 합계의 최소를 갱신

---

### 소스코드
- 메모리 : 1980KB
- 시간 : 156ms
```C
#include <stdio.h>
#include <limits.h>

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
```