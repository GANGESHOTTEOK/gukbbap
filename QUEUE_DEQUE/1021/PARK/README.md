
# 백준 1021번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.19 10:19

---

### 접근 방식
- 

### 소스코드
- 메모리 : 1116KB
- 시간 : 0ms
```C
#include <stdio.h>

// 2021.02.19 10:19

int main() {
	int N, M, Element, Index=1, Temp, Count = 0;
	int Queue[52] = {0,};
	
	scanf("%d %d", &N, &M);
	
	for(int i=0; i < M; i++) {
		scanf("%d", &Element);
		
		for(Temp = 0; Index != Element; Index = Index%N+1) {
			if (Queue[Index] == 0)
				Temp = Temp + 1;
		}
		
		Count = Count + (Temp < N-i-Temp ? Temp : N-i-Temp);
		Queue[Index] = 1;
	}
	
	printf("%d\n", Count);
	
	return 0;
}
```
