
# 2021년 01월 22일 금요일
# 백준 1149번 [RGB거리]
### https://www.acmicpc.net/problem/1149
---

### 문제 해결 날짜 및 시간
- 2021.01.18 23:24

---

### 접근 방식
- 처음에는 출발점이 있고 최소 비용과 그 색을 변수에 저장하고 다음에 반영하는 형식이었지만 비용이 동일할 때 문제가 생겨서 변경
- 이미 계산한 비용 2개 중 작은 비율과 지금의 비용을 더하는 방식으로 변경.
- 그리고 2차원 배열을 사용하는 것 대신에 1차원 배열 2개를 선언해서 사용.

---

### 소스코드
- 1116KB, 0ms
```C
#include<stdio.h>
#include<limits.h>

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
```
