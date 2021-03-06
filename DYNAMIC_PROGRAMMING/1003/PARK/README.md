
# 2021년 01월 18일 월요일
# 백준 1003번 [피보나치 함수]
### https://www.acmicpc.net/problem/1003

---

### 문제 해결 날짜 및 시간
- 2021.01.13 23:07

---
### 접근방식
- 그냥 재귀로는 시간초과가 나와서 찾아보니 메모이제이션이라는 게 있어서 그대로 사용
- N 피보나치에 0과 1을 출력하는 횟수는 f(N-1)과 f(N)과 같다는 것

![피보나치 설명](https://user-images.githubusercontent.com/69855374/105623161-f0813800-5e5a-11eb-93ec-dae8e4522535.jpg)

|N|F(0) 호출|F(1) 호출|
|:---:|:---:|:---:|
|0|1|0|
|1|0|1|
|2|1|1|
|3|1|2|
|4|2|3|
|5|3|5|

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>

// 이미 실행한 적 있는 과정을 다시 반복하여 중복연산을 만드는 것 대신에
// 메모이제이션(memoization)이라는 방법을 사용해서 이전 데이터를 저장해두는 것

int FiboArr[41]; // N은 0~40 

int main(void) {
	int T, N;
	
	scanf("%d", &T);
	
	FiboArr[0] = 0;
	FiboArr[1] = 1; // 초기 초기화 값 
	
	for (int i = 2; i < 41; i++) { // 피보나치 수열 생성 
		FiboArr[i] = FiboArr[i-1] + FiboArr[i-2];
	}
	
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		if (N == 0)
			printf("%d %d\n", 1, 0);
		else
			printf("%d %d\n", FiboArr[N-1], FiboArr[N]);
	}
	
	// 피보나치 수열의 0을 리턴하는 횟수, 1을 리턴하는 횟우에 대한 집합은
	// 계산하면 {1,0,1,1,2,3,5...}, {0,1,1,2,3,5,8...}
	// 피보나치를 따른다는 것을 알 수 있다. 
	
	return 0;
}
```
