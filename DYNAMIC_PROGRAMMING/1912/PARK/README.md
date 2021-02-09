# 2021년 02월 03일 수요일
# 백준 1912번 [연속합]
### https://www.acmicpc.net/problem/1912

---

### 문제 해결 날짜 및 시간
- 2021.01.29 23:33

---

### 접근 방식
- 보자마자 전형적인 DP라는 생각을 처음 가지게 해준 문제
- 경우의 수는 2가지 1) 계속 이어지는 경우, 2) 끊어지고 다시 시작하는 경우
- 2가지의 경우 중 더 큰 값을 가지는 것을 택하여 DP에 저장하면 되는 문제

---

### 소스코드
- 1116KB, 8ms
- 생각보다 시간이 많이 나왔던 문제
- 3가지 방법으로 풀이

- memoization할 배열을 선언하여 풀이
```C
#include <stdio.h>
#include <limits.h>

int NumArr[100000], ConsecutiveSum[100000];

int ReturnBiger(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N;
	int MaxSum = INT_MIN;
		
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &NumArr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		if (i == 0) // 0이면
			ConsecutiveSum[i] = NumArr[i]; // 저장된 값이 없으니 초기화
		else { // 0이 아니라면
			ConsecutiveSum[i] = ReturnBiger(ConsecutiveSum[i-1]+NumArr[i], NumArr[i]); // 계속 or 다시 중 더 큰 값 선택
		}
		MaxSum = ReturnBiger(ConsecutiveSum[i], MaxSum); // MaxSum 갱신
	}
	
	printf("%d\n", MaxSum);
	
	return 0;
}
```

- 배열 선언 없이 풀이
```C
#include <stdio.h>

int ReturnBiger(int a, int b) {
	return a > b ? a : b;
}

int main(void) {
	int N, Num;
	int MaxSum = -1001, ConsecutiveSum = -1001;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Num);
		Temp = ReturnBiger(ConsecutiveSum+Num, Num);
		MaxSum = ReturnBiger(MaxSum, ConsecutiveSum);
	}

	printf("%d\n", MaxSum);
	
	return 0;
}
```

- 삼항비교 연산을 줄이는 방식
```C
#include <stdio.h>

int main(void) {
	int N, Num;
	int MaxSum = -1001, ConsecutiveSum = 0;
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Num);
		if (ConsecutiveSum >= 0) // 양수면
			ConsecutiveSum = ConsecutiveSum + Num; // 그냥 더하기
		else // 음수면
			ConsecutiveSum = Num; // 새로운 값으로 갱신
		MaxSum = MaxSum > ConsecutiveSum ? MaxSum : ConsecutiveSum; // 위 과정이 가능하도록 MaxSum이 관리
	}
	
	printf("%d\n", MaxSum);
	
	return 0;
}
```
