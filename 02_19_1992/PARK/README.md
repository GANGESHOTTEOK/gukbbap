
# 백준 4949번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.19 17:22

---

### 접근 방식
- 2630 색종이 만들기와 동일한 문제.
- merge sort에서 착안
- 현재 면이 다 동일한 숫자로 되어 있는지 확인하는 함수
- 같지 않다면 다시 4개의 면으로 나누는 함수
- 재귀로 구현

### 소스코드
- 메모리 : 1132KB
- 시간 : 0ms
```C
#include <stdio.h>

int N, White = 0, Blue = 0;
int Screen[65][65];

int Split(int StartI, int StartJ, int NowN);
int CheckScreen(int IndexI, int IndexJ, int NowN);

int Split(int StartI, int StartJ, int NowN) {
	
	if (CheckScreen(StartI, StartJ, NowN)) { // 다 같은 면이 아니라면 나눠요! 
		printf("(");
		NowN = NowN/2;
		Split(StartI, StartJ, NowN);
		Split(StartI, StartJ+NowN, NowN);
		Split(StartI+NowN, StartJ, NowN);
		Split(StartI+NowN, StartJ+NowN, NowN);
		printf(")");
	}

	return 0;
}

int CheckScreen(int IndexI, int IndexJ, int NowN) { // 다 같은 색 맞아요??!! 
	int Color = Screen[IndexI][IndexJ];
	for (int i = IndexI; i < IndexI+NowN; i++) {
		for (int j = IndexJ; j < IndexJ+NowN; j++) {
			if (Color != Screen[i][j])
				return 1; // have to split 
		}
	}
	printf("%d", Color);
	return 0; // don't have to split
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) { // 배열 초기화 
		for (int j = 0; j < N; j++) {
			scanf("%1d", &Screen[i][j]);
		}
	}
	
	Split(0, 0, N);
		
	return 0;
}
```
