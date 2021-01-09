#include <stdio.h>

// 2020.12.31 18:41
// 시간복잡도 공부하기 
// 삽입, 선택, 버블로는 답이 안나와서 퀵 공부하고 풀이함

// 지역변수의 경우 윈도우에서 기본 스택의 사이즈는 1MB(변경가능)
// 동적할당 또는 전역변수, 스태틱(힙영역))의 경우는 크기 제한이 없다고 함

// quick sort을 사용하면 시간초과가 나오는 문제라고 함(운이 좋아야 AC 나온다고 함)
// merge sort 사용해서 풀기로 함
// 체감상 merge sort가 더 쉬운 느낌  

// 배열을 2배로 설정(조건이 정수)해서 Arr[2000002}로 설정해서
// 입력받는 숫자가 index가 되고 그 value를 1로 바꾸고
// value가 1인 걸 출력하는 방법도 있음 

int Arr[1000001] = {0,};
int SortedArr[1000001] = {0,};

int merge(int Left, int Right, int Middle, int Arr[]) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		//printf("i %d j %d\n", Arr[i], Arr[j]);
		if (Arr[i] < Arr[j]) {
			SortedArr[k] = Arr[i];
			//printf("!%d ", SortedArr[k]);
			i = i + 1;
		}
		else {
			SortedArr[k] = Arr[j];
			//printf("@%d ", SortedArr[k]);
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			SortedArr[k] = Arr[i];
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
		Arr[i] = SortedArr[i];
	}
	
}

int merge_sort(int Left, int Right, int Arr[]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, Arr);
		merge_sort(Middle+1, Right, Arr);
		merge(Left, Right, Middle, Arr);
	}
}

int main(void) {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	merge_sort(0, N-1, Arr);
	printf("\n\n");
	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]);
	}
	
	return 0;
}
// 5 21345
