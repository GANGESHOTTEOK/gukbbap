
# 2021년 01월 05일 화요일
# 백준 10989번 [수 정렬하기 3]
### https://www.acmicpc.net/problem/10989

---

### 문제 해결 날짜 및 시간
- 2020.01.01 17:28

---

### 접근 방식
- merge sort로 풀이 시 메모리 초과라서 counting sort로 풀이

---

### 소스코드
- 1156KB, 2720ms

```C
#include <stdio.h>

int Arr[10001] = {0,}; // 카운팅 배열 전역 변수로 선언

int main(void) {
	int N, Index = 0;
	
	scanf("%d", &N); // 입력 받는 수의 개수

	for (int i = 0; i < N; i++) {
		scanf("%d", &Index); // 값 입력 받기
		Arr[Index] = Arr[Index] + 1; // Index가 입력 받는 수. 그 수의 횟수가 몇개인 지 +1 
	}

	for (int i = 0; i < 10001; i++) { // 모든 수 탐색 
		for (int j = 0; j < Arr[i]; j++) { // 해당 수(i)에 값이 있다면(Arr[i]) for문이 한번 더 돌면서 출력 
			printf("%d\n", i);
		}
	}
	
	return 0;
}
```
