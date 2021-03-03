#include <stdio.h>
#include <stdlib.h>

// 틀린코 드 

int Coordinate[100001][2];

int main(void) {
	int N, MinX = 10001, MinY = 10001;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &Coordinate[i][0], &Coordinate[i][1]);
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			int TempX = abs(Coordinate[i][0]-Coordinate[j][0]);
			int TempY = abs(Coordinate[i][1]-Coordinate[j][1]);
			
			if (((TempX*TempX)+(TempY*TempY)) < ((MinX*MinX)+(MinY*MinY))) {
				MinX = TempX;
				MinY = TempY;
			}
			//printf("%d %d %d %d %d %d\n", i, j, MinX, MinY, TempX, TempY);
		}
	}
	
	printf("%d", (MinX*MinX)+(MinY*MinY));
	
	return 0;
}
/*
7
-5 0
-3 4
2 1
3 4
-1 1
8 8
1 7
*/
