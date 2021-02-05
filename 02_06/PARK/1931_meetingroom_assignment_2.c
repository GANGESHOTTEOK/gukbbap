#include <stdio.h>
//#include <algorithm>
#include <stdlib.h>
//using namespace std;

// 2021.02.03 23:41

// qsort 사용했고 compare 함수 정의.
// 구조체, 포인터 공부

// 익숙한 합병 정렬로도 풀어보기 

typedef struct Meeting{
	int Start;
	int End;
}Meeting;

Meeting Schedule[100001];

int compare(const void *a, const void *b) {
	
	Meeting *ptA = (Meeting *)a;
	Meeting *ptB = (Meeting *)b;
	
	if (ptA->End < ptB->End)
		return -1;
	else if (ptA->End == ptB->End) {
		if (ptA->Start < ptB->Start)
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
	qsort(Schedule, N, sizeof(Meeting), compare);
	
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
