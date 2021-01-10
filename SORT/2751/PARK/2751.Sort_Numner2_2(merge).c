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
// 5 21345
