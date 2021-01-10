
# 2021년 01월 09일 금요일
# 백준 11650번 [좌표 정렬하기]
### https://www.acmicpc.net/problem/11650

---

### 문제 해결 날짜 및 시간
- 2021.01.05 18:55

---

### 접근 방식
- bubble sort 시간 초과
- 7568_덩치.처럼 Rank배열에 순위 넣어 두고 순위 순서로 출력 -> 시간초과
- 2차원 배열 선언해서 merge sort 변형. x값이 같은 경우를 처리해야할 필요가 있어서 조건 추가

---

### 소스코드
- 2676KB, 64ms

```C
#include <stdio.h>

int Coordinate[100000][2] = {0,}; // 입력 받는 배열
int SortedCoordinate[100000][2] = {0,}; // 정렬된 배열

int merge(int Left, int Right, int Middle, int Coordinate[][2]) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		if (Coordinate[i][0] < Coordinate[j][0]) {
			SortedCoordinate[k][0] = Coordinate[i][0];
			SortedCoordinate[k][1] = Coordinate[i][1];
			i = i + 1;
		} // x값이 같을 경우 y로 판단을 위한 조건문
		else if (Coordinate[i][0] == Coordinate[j][0] && Coordinate[i][1] < Coordinate[j][1]) {
			SortedCoordinate[k][0] = Coordinate[i][0];
			SortedCoordinate[k][1] = Coordinate[i][1];
			i = i + 1;
		}
		else {
			SortedCoordinate[k][0] = Coordinate[j][0];
			SortedCoordinate[k][1] = Coordinate[j][1];
			j = j + 1;
		}
		k = k + 1;
	}
	
	if (i <= Middle) {
		for (; i <= Middle; i++) {
			SortedCoordinate[k][0] = Coordinate[i][0];
			SortedCoordinate[k][1] = Coordinate[i][1];
			k = k + 1;
		}
	}
	else if (j <= Right) {
		for(; j <= Right; j++) {
			SortedCoordinate[k][0] = Coordinate[j][0];
			SortedCoordinate[k][1] = Coordinate[j][1];
			k = k + 1;
		}
	}

	for (int i = Left; i <= Right; i++) {
		Coordinate[i][0] = SortedCoordinate[i][0];
		Coordinate[i][1] = SortedCoordinate[i][1];
	}
	
}

int merge_sort(int Left, int Right, int Coordinate[][2]) {
	int Middle = (Left+Right)/2;
	
	if (Left < Right) {
		merge_sort(Left, Middle, Coordinate);
		merge_sort(Middle+1, Right, Coordinate);
		merge(Left, Right, Middle, Coordinate);
	}
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Coordinate[i][0], &Coordinate[i][1]); // x, y 입력 
	}
	
	merge_sort(0, N-1, Coordinate); // merge sort 시작 
	
	for (int i = 0; i < N; i++) {
		printf("%d %d\n", Coordinate[i][0], Coordinate[i][1]); // 출력
	}
	return 0;
}
```
