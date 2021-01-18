#include <stdio.h>
#include <stdlib.h>

// 21.01.12 17:33
// 2중 for문을 사용하지 않고 count / 9, count % 9 사용해서 index 구함
// 만약 맞지 않는 수가 채워지는 경우 그걸 처음부터 다시 0으로 채울 수 없어서 틀린 것
// board에 수를 넣는 순서를 바꿈
// 답이 여러 개인 경우 1개를 만들면 끝내야함
// exit(0 or -1), stdlib.h

// 내 코드와 비교해보기  https://www.acmicpc.net/source/5270369
// https://www.acmicpc.net/source/24632801
// https://www.acmicpc.net/source/6715519

int Sudoku[9][9];
int Count = 0;

int CheckSudoku(int IndexI, int IndexJ, int NowNumber) {
	int BoxIndexI = IndexI-IndexI%3; //for squre index
	int BoxIndexJ = IndexJ-IndexJ%3;
	
	for (int i = 0; i < 9; i++) {
		if (i != IndexI && Sudoku[i][IndexJ] == NowNumber) { //row check
			return 0; 
		}
		else if (i != IndexJ && Sudoku[IndexI][i] == NowNumber) { //col check
			return 0;
		}
	}
	
	for (int j = BoxIndexI; j < BoxIndexI+3; j++) { // squre check
		for (int k = BoxIndexJ; k < BoxIndexJ+3; k++) {
			if ((j != IndexI || k != IndexJ) && Sudoku[j][k] == NowNumber) {
				return 0;
			}
		}
	}
	return 1;
}

int SolveSudoku(int Count) {
	if (Count == 81) { // 스도쿠 칸의 개수는 81개. 0부터 시작했으니 81이면
		
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				printf("%d ", Sudoku[i][j]); // 스도쿠를 출력하세요 
			}
			printf("\n");
		}
		printf("\n");
		exit(0);
	}
	
	int i = Count / 9; // row
	int j = Count % 9; // col

	if (Sudoku[i][j] == 0) { // 현재 index에 수가 없으면 
		for (int k = 1; k <= 9; k++) {
			if (CheckSudoku(i, j, k)) { // 현재 k가 들어가기에 알맞은 수인지 
				Sudoku[i][j] = k; // 맞으면 k 대입 
				SolveSudoku(Count + 1); // 다음 index 
				Sudoku[i][j] = 0; // 1~9 중 맞는 수가 없을 떄를 대비한 초기화 
			}

		}
	}
	else { // 현재 index에 수가 있으면 
		SolveSudoku(Count + 1); // 다음 index 
	}

	return 0;
}

int main(void) {
	
	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			scanf("%d", &Sudoku[i][j]);
		}
	}
	
	SolveSudoku(0);
	
	return 0;
}

/*
test case
0 0 2 0 9 6 0 0 0
0 0 9 0 5 8 7 0 0
0 5 0 2 7 1 9 4 0
0 0 5 8 1 7 4 0 0
0 0 0 9 3 5 2 1 7
1 9 7 6 2 4 8 3 5
0 6 4 5 8 3 1 7 0
0 0 1 7 4 9 6 0 0
0 0 0 1 6 2 0 0 4

0 6 0 0 0 0 2 0 9
0 0 0 8 2 0 5 0 0
0 1 0 9 0 3 0 0 0
3 7 0 0 9 0 0 0 6
1 0 0 0 0 0 0 0 8
2 0 0 0 4 0 0 5 1
0 0 0 5 0 4 0 9 0
0 0 3 0 7 9 0 0 0
5 0 9 0 0 0 0 6 0

0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 0 0
*/
