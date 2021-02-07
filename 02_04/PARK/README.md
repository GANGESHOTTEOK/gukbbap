# 2021년 02월 04일 목요일
# 백준 12865번 [평범한 배낭]
### https://www.acmicpc.net/problem/12865

---

### 문제 해결 날짜 및 시간
- 2021.02.02 21:48

---

### 접근 방식
- 2차원 배열을 어떻게 선언할지, 작은 문제로 어떻게 쪼갤지 제대로 생각 못한 문제
- 일단 2차원 배열을 Backpack[넣을 수 있는 물건 수][넣을 수 있는 무게]로 선언, 그리고 무게와 가치 배열(Weight[101], Value[101]) 선언 후 물건은 넣는게 좋을지 빼는게 좋을 지 판단
- 2중 for문을 사용해서 첫번째 for문에서는 물건의 개수를 1개씩 추가하고 2번째 for문에서는 무게를 1씩 늘린다.
- 현재 물건[i]의 무게가 현재 가방에 들어가는 지 확인. if (j - Weight[i] >= 0)
- 들어간다면 i-1개까지 넣고 j - Weight[i]의 무게를 가진 가방에 Value[i]를 추가하는 것과 현재 무게에 i-1개까지 넣은 가방(지금 물건을 넣지 않는 것) 중 무엇의 가치가 더 높은지 비교 후 대입

---

### 소스코드
- 40568KB, 32ms
- +) 메모리를 줄이기 위해 1차원 배열로 선언할 경우 탐색은 역방향으로 해야함
```C
#include <stdio.h>

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
```
