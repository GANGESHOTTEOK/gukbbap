
# 백준 1874번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.15 23:39

---

### 접근 방식
- 

### 소스코드
- 메모리 : 1896KB
- 시간 : 16ms
```C
#include <stdio.h>

// 2021.02.15 23:39

int Stack[100002];
char Calc[400008];

int main(void) {
	int N, NowNum, Index = -1, Temp = 1, CalcIndex = 0;
	
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		scanf("%d", &NowNum);
		
		if (Stack[Index] < NowNum) {
			for (int j = Temp; j <= NowNum; j++) {
				Index = Index + 1;
				Stack[Index] = j;
				Calc[CalcIndex++] = '+';
				Calc[CalcIndex++] = '\n';
			}
			Temp = NowNum+1;
		}
		else if (Stack[Index] != NowNum) {
			printf("NO\n");
			return 0;
		}
		
		if (Stack[Index] == NowNum) {
			Index = Index - 1;
			Calc[CalcIndex++] = '-';
			Calc[CalcIndex++] = '\n';
		}
	}

	printf("%s", Calc);
	return 0;
}
```