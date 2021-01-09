#include <stdio.h>

// 2020.12.30 09:34
// 그냥 최소 구해서 계속 출력하면 되는데 문제가 정렬이니 그렇게 풀이 
// selection sort로 풀이함 
// bubble sort, insertion sort 추가로 다시 학습하기
// 삽입정렬, 선택정렬, 버블정렬 순으로 빠르다고 함.
// 선택정렬의 경우 BEST에서는 시간복잡도가 n^2가 아닌 n 
// reference : https://gmlwjd9405.github.io/2018/05/06/algorithm-insertion-sort.html

int main(void) {
	int N, Min = 0, MinIndex = 0, Temp = 0;
	int Arr[1000] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Arr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		Min = Arr[i];
		for (int j = i; j < N; j++) {
			if (Arr[j] <= Min) {
				Min = Arr[j];
				MinIndex = j;
			}
		}
		Temp = Arr[i];
		Arr[i] = Arr[MinIndex];
		Arr[MinIndex] = Temp; 
	}

	for (int i = 0; i < N; i++) {
		printf("%d\n", Arr[i]);
	}
	
	return 0;
}
