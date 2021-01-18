
# 2021년 01월 14일 목요일
# 백준 9663번 [스도쿠]
### https://www.acmicpc.net/problem/2580

---

### 문제해결 날짜 및 시간
- 21.01.12 17:33
---

### 접근방식
- 2중 for문으로 스도쿠를 순회하는 방식 => 시간초과
- 스도쿠의 특성 81의 몫과 나머지를 활용해서 index가져오고 순회로 변경
- 백트래킹으로 0 대신 들어갈 경우의 수 함수, 해당 수가 들어 갈 수 있는지 판단하는 함수

---

### 소스코드
- 1116KB, 256ms

```C
#include <stdio.h>
#include <stdlib.h>

// 21.01.12 17:33
// 2중 for문을 사용하지 않고 count / 9, count % 9 사용해서 index 구함
// 만약 맞지 않는 수가 채워지는 경우 그걸 처음부터 다시 0으로 채울 수 없어서 틀린 것
// board에 수를 넣는 순서를 바꿈
// 답이 여러 개인 경우 1개를 만들면 끝내야함
// exit(0 or -1), stdlib.h

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
```
