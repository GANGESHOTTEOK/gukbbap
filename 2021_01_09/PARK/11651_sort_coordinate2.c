#include <stdio.h>

// 2021.01.05 18:58

// 11650_sort_coordinate에서 처음 입력 받을 때 순서만 변경
// scanf("%d %d", &Coordinate[i][0], &Coordinate[i][1]); -> scanf("%d %d", &Coordinate[i][1], &Coordinate[i][0]);

int Coordinate[100000][2] = {0,};
int SortedCoordinate[100000][2] = {0,};

int merge(int Left, int Right, int Middle, int Coordinate[][2]) {
	
	int i = Left, j = Middle+1, k = Left;
	
	while(i <= Middle && j <= Right) {
		if (Coordinate[i][0] < Coordinate[j][0]) {
			SortedCoordinate[k][0] = Coordinate[i][0];
			SortedCoordinate[k][1] = Coordinate[i][1];
			i = i + 1;
		}
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
		scanf("%d %d", &Coordinate[i][1], &Coordinate[i][0]);
	}
	
	merge_sort(0, N-1, Coordinate);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", Coordinate[i][1], Coordinate[i][0]);
	}
	return 0;
}
//4
//1 -1
//1 1
//-1 1
//-1 -1
