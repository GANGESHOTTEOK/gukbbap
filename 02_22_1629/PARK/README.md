# 2021년 02월 22일 월요일
# 백준 1629번 곱셈
### https://www.acmicpc.net/problem/1629

---

### 문제 해결 날짜 및 시간
- 2021.02.22 21:53

---

### 접근 방식
- 4^8 = 16^4 = 256^2 = ANS에 따라서 함수 정의
- 단 현재 거듭제곱이 홀수인 경우 현재 수를 한번 더 곱해준다

### 소스코드
- 메모리 : 2016KB
- 시간 : 0ms
```c
#include <stdio.h>

int A, B, C, Ans = 0;

int Multiple(int Num, int Repeat) {
	if (Repeat == 0)
		return 1;
	
	long long int Temp = Multiple(Num, Repeat/2);
	long long int Ans = Temp * Temp % C; // square

	if (Repeat&1) // odd 
		Ans = Ans * Num % C;
	
	return Ans;
}

int main(void) {
	
	scanf("%d %d %d", &A, &B, &C);

	Ans = Multiple(A, B)%C;
	
	printf("%d\n", Ans);
	
	return 0;
}
```
