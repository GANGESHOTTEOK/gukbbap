
# 백준 1780번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.19 20:06

---

### 접근 방식
- 2630 색종이 만들기와 동일한 문제
- 차이가 있다면 4개의 면으로 나누는 것이 아닌 9개의 면으로 나누는 것
- merge sort에서 착안
- 현재 면이 다 동일한 수로 되어있는지 확인하는 함수
- 동일하지않다면 나누는 함수
- for을 사용해서 9개의 면으로 함수호출보다 그냥 9개 다 적는게 더 빠름

### 소스코드
- 메모리 : 19816KB
- 시간 : 500ms
```C
#include <stdio.h>

// index를 row, col로 했으면 더 보기 편했을 듯 
// 생각보다 시간이 많이 느림 -> for 사용 : 524ms, 안사용 : 500ms

int N, MinusOne = 0, PlusOne = 0, Zero = 0;
int Paper[2188][2188];

int Split(int StartI, int StartJ, int NowN);
int CheckPaper(int IndexI, int IndexJ, int NowN);

int Split(int StartI, int StartJ, int NowN) {
	if (CheckPaper(StartI, StartJ, NowN)) { // 다르면 나눠요 나눠!! 
		NowN = NowN/3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Split(StartI+NowN*i, StartJ+NowN*j, NowN);
			}
		}
		/*
		Split(StartI, StartJ, NowN);
		Split(StartI, StartJ+NowN, NowN);
		Split(StartI, StartJ+NowN+NowN, NowN);
		Split(StartI+NowN, StartJ, NowN);
		Split(StartI+NowN, StartJ+NowN, NowN);
		Split(StartI+NowN, StartJ+NowN+NowN, NowN);
		Split(StartI+NowN+NowN, StartJ, NowN);
		Split(StartI+NowN+NowN, StartJ+NowN, NowN);
		Split(StartI+NowN+NowN, StartJ+NowN+NowN, NowN);
		*/
	}
	return 0;
}

int CheckPaper(int IndexI, int IndexJ, int NowN) { // 당신은 다 같은 색인가요?? 
	int Color = Paper[IndexI][IndexJ];
	for (int i = IndexI; i < IndexI+NowN; i++) {
		for (int j = IndexJ; j < IndexJ+NowN; j++) {
			if (Color != Paper[i][j])
				return 1; // have to split 
		}
	}
	Color == 1 ? PlusOne++ : (Color == -1) ? MinusOne++ : Zero++;
	return 0; // don't have to split
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) { // 배열 초기화 
		for (int j = 0; j < N; j++) {
			scanf("%d", &Paper[i][j]);
		}
	}
	
	Split(0, 0, N);
	
	printf("%d\n%d\n%d\n", MinusOne, Zero, PlusOne);
	
	return 0;
}
```
