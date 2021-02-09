# 2021년 02월 06일 토요일
# 백준 1931번 회의실 배정
### https://www.acmicpc.net/problem/1931

---

### 문제 해결 날짜 및 시간
- 2021.02.03 23:41

---

### 접근 방식
- 처음에는 정렬을 하지 않고 재귀로 풀었는데 입력된 회의의 값이 같은 경우 처리가 제대로 안됐음.
- 그래서 정렬 후 풀이로 변경. 정렬 후 풀이의 이점은 어떠한 조건 없이 끝나는 시간이 작은 회의부터 순회가 가능하다는 점.
- 구조체를 이용해 start와 end를 정의하고 모든 회의들을 정렬한 후 EndTime(최근 회의 종료 시간)을 따로 정의하고 갱신하며 가능 회의 개수를 추가하는 방식으로 풀이

---

### 소스코드
- 2680KB, 40ms
- qsort
```C
#include <stdio.h>
//#include <algorithm>
#include <stdlib.h>
//using namespace std;

typedef struct Meeting{ // 구조체 선언
	int Start;
	int End;
}Meeting;

Meeting Schedule[100001]; // 회의 배열 선언

int compare(const void *a, const void *b) { // 사용자 정의 compare
	
	Meeting *ptA = (Meeting *)a;
	Meeting *ptB = (Meeting *)b;
	
	if (ptA->End < ptB->End) // 끝나는 시간 기준으로 오름차순
		return -1;
	else if (ptA->End == ptB->End) { // 끝나는 시간 같다면
		if (ptA->Start < ptB->Start) // 시작하는 시간 기준으로 오름차순
			return -1;
		else
			return 1;
	}
	else
		return 1;
}

int main(void) {
	int N;
	int Count = 1, EndTime = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Schedule[i].Start, &Schedule[i].End);
	}
	
	//sort(Meeting, Meeting+N, compare);
	qsort(Schedule, N, sizeof(Meeting), compare); // 정렬
	
	EndTime = Schedule[0].End; // 배열의 처음 값으로 최근 회의 종료 시간 초기화
	for (int i = 1; i < N; i++) { // 배열의 2번째 값부터 순회
		if (Schedule[i].Start >= EndTime) { // 현재 index의 회의 시작시간이 최근 종료 시간보다 크다면
			Count = Count + 1; // 회의 가능 개수++
			EndTime = Schedule[i].End; // 최근 회의 종료 시간 갱신
		}
	}
	
	printf("%d\n", Count);
	
	return 0;
}
```

- 2676KB, 44ms
- merge sort
```C
#include <stdio.h>
#include <stdlib.h>

typedef struct Meeting{
	int Start;
	int End;
}Meeting;

Meeting Schedule[100001];
Meeting SortedSchedule[100001];

int merge(int Left, int Right, int Middle) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		if (Schedule[i].End < Schedule[j].End) {
			SortedSchedule[k] = Schedule[i];
			i = i + 1;
		}
		else if (Schedule[i].End == Schedule[j].End) {
			if (Schedule[i].Start < Schedule[j].Start) {
				SortedSchedule[k] = Schedule[i];
				i = i + 1;
			}
			else {
				SortedSchedule[k] = Schedule[j];
				j = j + 1;
			}
		}
		else {
			SortedSchedule[k] = Schedule[j];
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			SortedSchedule[k] = Schedule[i];
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			SortedSchedule[k] = Schedule[j];
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		Schedule[i] = SortedSchedule[i];
	}
	
}

int merge_sort(int Left, int Right) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle);
		merge_sort(Middle+1, Right);
		merge(Left, Right, Middle);
	}
}

int main(void) {
	int N;
	int Count = 1, EndTime = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Schedule[i].Start, &Schedule[i].End);
	}
	
	merge_sort(0, N-1);
	
	EndTime = Schedule[0].End;
	for (int i = 1; i < N; i++) {
		if (Schedule[i].Start >= EndTime) {
			Count = Count + 1;
			EndTime = Schedule[i].End;
		}
	}
	
	printf("%d\n", Count);
	
	return 0;
}
```
