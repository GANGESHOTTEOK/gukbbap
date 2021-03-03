# 2021년 02월 26일 금요일
# 백준 6549번 히스토그램에서 가장 큰 직사각형
### https://www.acmicpc.net/problem/6549

---
### 문제 해결 날짜 및 시간
- 

---

### 접근 방식
- 가장 작은 높이를 찾고 현재 범위와 높이를 곱하여 직사각형을 구한다
- 가장 작은 높이를 가진 index를 기준으로 잡은 뒤 앞 구역과 뒤 구역으로 나누고 다시 이 2구역을 위 방법으로 반복
- 가장 작은 높이를 가진 index를 매번 찾다 보니 시간초과 나는 중

---

### 소스코드
- 메모리 : KB
- 시간 : ms
```c
#include <stdio.h>

int Height[100001];

int FindMinHeight(int Start, int End) { // 여기에서 시간초과 나는 듯
	int MinHeightIndex = Start;
	
	for (int i = Start; i < End; i++)
		if (Height[i] < Height[MinHeightIndex])
			MinHeightIndex = i;
	
	return MinHeightIndex;
}

long long int CalcMaxArea(int Start, int End) {
	int MinHeightIndex = FindMinHeight(Start, End);
	long long int MaxRectangle = Height[MinHeightIndex] * (End - Start);
	long long int Temp = 0;
	
	if (Start == End)
		return MaxRectangle;
	
	if(Start < MinHeightIndex) {
		Temp = CalcMaxArea(Start, MinHeightIndex);
		if (Temp > MaxRectangle)
			MaxRectangle = Temp;
	}
	
	if(MinHeightIndex < End) {
		Temp = CalcMaxArea(MinHeightIndex+1, End);
		if (Temp > MaxRectangle)
			MaxRectangle = Temp;
	}
	
	return MaxRectangle;
}

int main(void) {
	int N;

	while(1) {
		scanf("%d", &N);
		
		if (N == 0)
			return 0;
		
		for(int i = 0; i < N; i++)
			scanf("%d", &Height[i]);
		
		printf("%lld\n", CalcMaxArea(0, N));
	}
	
	
	return 0;
}

```
