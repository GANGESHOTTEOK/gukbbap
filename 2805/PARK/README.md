
# 2021년 3월
# 백준 2805번 [나무 자르기]
### https://www.acmicpc.net/problem/2805
---

### 문제 해결 날짜 및 시간

- 2021.03.19 22:25

---

### 접근 방식
- 톱의 길이를 범위로 이분탐색
- 자른 부분의 합과 원하는 합 비교 후 더 크면 최대 톱 길이 

### 소스코드
- 메모리 : 5020KB
- 시간 : 228ms
```C
#include <stdio.h>

int Tree[1000001];

int main(void) {
	int N, M, LongestSaw = 0, Start = 0, End = 0;
	
	scanf("%d %d", &N, &M);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Tree[i]);
		End = Tree[i] > End ? Tree[i] : End; // End를 가지기 위한 비교, 최대 나무 길이 갱신
	}
	
	while(Start <= End) { // 톱에 대한 이분탐색 
		int Mid = (Start + End)/2;
		long long Sum = 0;
		
		for(int i = 0; i < N; i++) {
			if (Tree[i] > Mid)
				Sum = Sum + (Tree[i]-Mid); // 자른 부분의 
		}

		if (Sum >= M) {
			Start = Mid + 1;
			LongestSaw = (Mid > LongestSaw) ? Mid : LongestSaw; // 최대 톱 길이 갱신 
		}
		else
			End = Mid-1;
	}
	
	printf("%d\n", LongestSaw);
	
	return 0;
}
```
