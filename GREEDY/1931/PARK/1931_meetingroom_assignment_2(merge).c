#include <stdio.h>
//#include <algorithm>
#include <stdlib.h>
//using namespace std;

// 2021.02.04 10:33

// qsort 사용했고 compare 함수 정의.
// 구조체, 포인터 공부

// 익숙한 합병 정렬로도 풀어보기 -> 완료 

typedef struct Meeting{
	int Start;
	int End;
}Meeting;

Meeting Schedule[100001];
Meeting SortedSchedule[100001];

int merge(int Left, int Right, int Middle) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		//printf("i %d j %d\n", Arr[i], Arr[j]);
		if (Schedule[i].End < Schedule[j].End) {
			SortedSchedule[k] = Schedule[i];
			//printf("!%d ", SortedArr[k]);
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
			//printf("@%d ", SortedArr[k]);
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
/*
5
4 4
4 4
3 4
2 4
1 4
*/
