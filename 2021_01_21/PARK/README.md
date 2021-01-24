
# 2021년 01월 21일 목요일
# 백준 9461번 [파도반 수열]
### https://www.acmicpc.net/problem/9461
---

### 문제 해결 날짜 및 시간
- 2021.01.17 21:31

---

### 접근 방식
- 파도판 수열은 ([i] = [i-1] + [i-5]) 이 규칙을 따른다.
- 따라서 이 규칙에 맞춰 메모이제이션을 하면 된다

---

### 소스코드
- 1116KB, 0ms
```C
#include<stdio.h>

int main(void) {
	int T, N;
	long long int PadovanSequence[100] = {1, 1, 1, 2, 2};
	
	scanf("%d", &T);
	
	for (int i = 5; i < 100; i++) {
		PadovanSequence[i] = PadovanSequence[i-5] + PadovanSequence[i-1];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		printf("%lld\n", PadovanSequence[N-1]);
	}
	
	return 0;
} 
```
