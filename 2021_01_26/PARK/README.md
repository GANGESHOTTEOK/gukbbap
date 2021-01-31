
# 2021년 01월 26일 화요일
# 백준 1453번 [1로 만들기]
### https://www.acmicpc.net/problem/1463

---

### 문제 해결 날짜 및 시간
- 2021.01.21 01:49

---
### 접근방식
- 1) 3과 2 모두로 나누어 떨어지는 경우 2) 3으로만 나누어 떨어지는 경우 
- 3) 2로만 나누어 떨어지는 경우 4) 1을 뺀 경우
- 위 4가지 경우에 맞춰 해당 Index의 Value에 1을 만드는데 가장 작은 Count 저장.
- ex) 계산 할 값이 5라면 CalcCnt[5] = CalcCnt[4] + 1 이 되는 것

---
### 소스코드
- 5020KB 8ms

```C
#include <stdio.h>

// 애해하기. 훨씬 간단한 코드  https://www.acmicpc.net/source/9193008

int CalcCnt[1000001] = {0,1,1};

int ReturnSmaller(int a, int b) {
	return a <= b ? a : b;
}

int MakeOneCount(int Index) {
	if (Index%3 == 0 && Index%2 == 0) // 3과 2로 나누어 떨어지는 경우
		return ReturnSmaller(ReturnSmaller(CalcCnt[Index/3-1], CalcCnt[Index-2]), CalcCnt[Index/2-1])+1;
	else if (Index%3 == 0) // 3으로 나누에 떨어지는 경우
		return ReturnSmaller(CalcCnt[Index/3-1], CalcCnt[Index-2])+1;
	else if (Index%2 == 0) // 2로 나누어 떨어지는 경우
		return ReturnSmaller(CalcCnt[Index/2-1], CalcCnt[Index-2])+1;
	else // 1 빼기
		return CalcCnt[Index-2]+1;
}

int main(void) {
	int N;
	
	scanf("%d", &N);
	
	for (int i = 3; i < N; i++) {
		CalcCnt[i] = MakeOneCount(i+1);
	}
	
	printf("%d\n", CalcCnt[N-1]);
	
	return 0;
}
```
