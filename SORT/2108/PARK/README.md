
# 2021년 01월 06일 수요일
# 백준 2108번 [통계학]
### https://www.acmicpc.net/problem/2108

---

### 문제 해결 날짜 및 시간
- 2021.01.04 00:22

---

### 접근 방식
- 산술평균은 입력 받을 때 Sum 구해서 round로 반올림하고 출력
- 중앙값은 merge sort 사용해서 N/2번째 배열의 값 출력
- 최빈값은 카운팅 배열로 풀이. 가장 높은 빈도와 가장 빈도가 높은 수 중 가장 작은 수를 구하고 최빈값이 1개인지 판단하고 아니면 2번째 최빈값 출력
- 범위는 입력 받을 때 Min, Max 구해서 Max-Min

---

### 소스코드
- 5052KB, 116ms

```C
#include <stdio.h>
#include <math.h>

int CountArr[8001] = {0,}; // 카운팅 배열(최빈값을 위해 사용)
int SortedArr[500001] = {0,}; // merge sort로 정렬된 배열
int Arr[500001] = {0,}; // 모든 수를 나열할 배열

// 나눠진 배열을 하나로 합치며 정렬하는 함수
int merge(int Start, int End, int Middle, int Arr[]) {
	int i = Start, j = Middle+1, k = Start;
	
	while(i <= Middle && j <= End) {
		if (Arr[i] < Arr[j]) {
			SortedArr[k] = Arr[i];
			i = i + 1;
		}
		else {
			SortedArr[k] = Arr[j];
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for(; i <= Middle; i++) {
			SortedArr[k] = Arr[i];
			k = k + 1;
		}
	}
	else if (j <= End) {
		for(; j <= End; j++) {
			SortedArr[k] = Arr[j];
			k = k + 1;
		}
	}
	
	for(int l = Start; l <= End; l++) {
		Arr[l] = SortedArr[l];
	}
	
}

// 배열의 크기가 1이 될 때까지 나누는 함수 
int merge_sort(int Start, int End, int Arr[]) {
	int Middle = (Start + End)/2;
	
	if (Start < End) {
		merge_sort(Start, Middle, Arr);
		merge_sort(Middle+1, End, Arr);
		merge(Start, End, Middle, Arr);
	}
}

int main(void) {
	int N, Index, Max = 0, Min = 8001, Sum = 0;
	int Bool = 0, MaxCount = 0, MaxCountMinNum = 8001, SecNum = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Index);
		Arr[i] = Index; // 모든 수를 Arr배열에 삽입 
		Sum = Sum + Index; //산술 평균에 사용할 총 합계 
		
		Index = Index + 4000; // 카운팅 배열을 위한 Index (-4000 == 0, 4000 == 8000. 음수를 표현하기 위해서)
		
		CountArr[Index] = CountArr[Index] + 1; // 해당 값의 수가 몇 개인지를 넣는 배열 

		if (Index > Max)
			Max = Index; // 범위를 출력하기 위한 Max 
		if (Index < Min)
			Min = Index; // 범위를 출력하기 위한 Min 
	}
	
	// 산술평균
	printf("%d\n", (int)round((double)Sum/N)); // round 함수를 이용하여 반올림. 
	
	// 중앙값
	merge_sort(0, N-1, Arr); // merge sort의 시작
	printf("%d\n", Arr[N/2]); // N/2 후에 +1을 하지 않은 이유는 배열은 0부터 시작하니까
	
	// 최빈값
	for (int i = Min; i < 8001; i++) {
		if (CountArr[i] > MaxCount) { 
			MaxCount = CountArr[i]; // 가장 많이 입력된 수의 개수  MaxCount
			MaxCountMinNum = i; // 가장 빈도가 높은 수 중 가장 작은 수
		}
	}
	
	for (int i = MaxCountMinNum+1; i < 8001; i++) { // 최빈값이 단 하나 인지 검사 
		if (CountArr[i] == MaxCount)
			Bool = 1; // 단 하나가 아니라면 Bool = 1 
	}
	
	if (Bool) { // 최빈값이 하나가 아니라면 
		for (int j = MaxCountMinNum+1; j < 8001 && !SecNum; j++) { //가장 빈도가 높은 수 중 2번째로  작은 수가 나올 때까지
			if (CountArr[j] == MaxCount)
				SecNum = j;
		}
	}
	else
		SecNum = MaxCountMinNum; // 단 하나라면 최빈값은 가장 빈도가 높은 수 중 가장 작은 수

	printf("%d\n", SecNum-4000); // 카운팅 배열이니까 원래 값은 -4000을 한 수 
	printf("%d\n", Max-Min); // 처음 입력 받을 때 구해둔 Max와 Min을 활용한 범위 
	
	return 0;
}
```