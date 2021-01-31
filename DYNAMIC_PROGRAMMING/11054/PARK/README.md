
# 2021년 01월 30일 토요일
# 백준 11054번 [가장 긴 바이토닉 부분 수열]
### https://www.acmicpc.net/problem/11054

---

### 문제 해결 날짜 및 시간
- 2021.01.26 21:19

---
### 접근방식
- 11053 방식을 2번 사용.
- 앞에서 부터 LIS, 뒤에서 부터 LIS
- 2개 Arr의 Value를 더하고
- 가장 큰 Value에서 1을 빼고 출력(변환점의 수가 2번 들어감. 그래서 -1)

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>

int main(void) {
	int N, MaxLen = 0;
	int BitonicSequence[1001];
	int BitonicIncLen[1001] = {0,};
	int BitonicDecLen[1001] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &BitonicSequence[i]);
	}
	
	for (int i = 0; i < N; i++) {
		int IncreaseMin = 0;
		for (int l = 0; l < i; l++) {
			if (BitonicSequence[l] < BitonicSequence[i]) {
				if (IncreaseMin < BitonicIncLen[l]) {
					IncreaseMin = BitonicIncLen[l];
				}
			}
		}
		BitonicIncLen[i] = IncreaseMin + 1;
	}

	for (int i = N-1; i >= 0; i--) {
		int DecreaseMin = 0;
		for (int j = N-1; j > i; j--) {
			if (BitonicSequence[j] < BitonicSequence[i]) {
				if (DecreaseMin < BitonicDecLen[j]) {
					DecreaseMin = BitonicDecLen[j];
				}
			}
		}
		BitonicDecLen[i] = DecreaseMin + 1;		
	}

	for (int i = 0 ; i < N; i++) {
		if (BitonicIncLen[i] + BitonicDecLen[i] > MaxLen)
			MaxLen = BitonicIncLen[i] + BitonicDecLen[i];
	}
	
	printf("%d\n", MaxLen-1);
	
	return 0;
}
```
