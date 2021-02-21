# 백준 2164번 문제


---


### 문제 해결 날짜 및 시간


- 2021.02.16 23:30


---


### 접근 방식
- 


### 소스코드
- 메모리 : 5020KB
- 시간 : 4ms
```C
#include <stdio.h>

int Queue[1000001];
int main(void) {
	int N, End;
	
	scanf("%d", &N);
	
	End = N-1;
	
	for (int i = 0; i <= End; i++) {
		if (i < N)
			Queue[i] = i+1;
		if ((i&1))
			Queue[++End] = Queue[i];
	}
	
	if (N==1)
		printf("1\n");
	else
		printf("%d", Queue[End-1]);
	
	
	return 0;
}
```