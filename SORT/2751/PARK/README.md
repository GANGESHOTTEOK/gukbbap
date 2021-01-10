
# 2021년 01월 04일 월요일
# 백준 2751번 [수 정렬하기 2]
### https://www.acmicpc.net/problem/2751

---

### 문제 해결 날짜 및 시간
- 2020.12.31 18:41

---

### 접근 방식
- 알고 있는 정렬로는 풀 수 없어서 quick sort를 공부해서 풀이했으나 시간 초과(quick sort 저격 케이스가 있다는 글을 보게 됨. 아마도 처음 값을 pivot으로 잡아서 그런 듯)
- 그래서 merge sort 추가로 공부해서 해결

---

### 소스코드
- 8928KB, 440ms

```C
#include <stdio.h>

int Arr[1000001] = {0,}; // 처음 수를 입력 받는 배열
int SortedArr[1000001] = {0,}; // 정렬된 배열 

int merge(int Left, int Right, int Middle, int Arr[]) {
	
	int i = Left, j = Middle+1, k = Left; //Arr을 위한 i,j SortedArr을 위한 k 
	
	while(i <= Middle && j <= Right) { // 둘중에 뭐가 작은지 모르니
		if (Arr[i] < Arr[j]) { // 둘 주에 뭐가 작은 지 판단
			SortedArr[k] = Arr[i]; // 작은 수를 대입
			i = i + 1; // 대입 했으니까 다음 인덱스로
		}
		else {
			SortedArr[k] = Arr[j];
			j = j + 1;
		}
		k = k + 1; //SortedArr에 대입 했으니까 다음 인덱스로
	}
	
	if (i <= Middle) { // i의 길이가 j보다 더 긴 경우
		for (; i <= Middle; i++) {
			SortedArr[k] = Arr[i]; // 비교하지 못하고 남은 부분을 뒤에 추가
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			SortedArr[k] = Arr[j];
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		Arr[i] = SortedArr[i]; // 정렬된 배열을 Arr에 대입
	}
	
}

int merge_sort(int Left, int Right, int Arr[]) {
	int Middle = (Left+Right)/2; // 배열을 나눌 기준
	
	if (Left < Right) { // 시작점이 끝점을 넘지 않을 때까지(배열 크기 2이상만 통과)
		merge_sort(Left, Middle, Arr); // 시작점(Left)부터 끝점(Middle)까지 배열 나누기
		merge_sort(Middle+1, Right, Arr); // 시작점(Middle+1)부터 끝점(Right)까지 배열 나누기
		merge(Left, Right, Middle, Arr); // merge sort 시작
	}
}

int main(void) {
	int N;

	scanf("%d", &N); // 입력 되는 수

	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]); // 배열에 수 받기
	}
	
	merge_sort(0, N-1, Arr); // merge sort 시작 

	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]); // 정렬된 배열 출력
	}
	
	return 0;
}
```
