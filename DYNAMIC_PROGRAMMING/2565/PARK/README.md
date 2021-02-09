# 2021년 02월 01일 월요일
# 백준 [전깃줄]
### https://www.acmicpc.net/problem/2565

---

### 문제 해결 날짜 및 시간
- 2021.01.26 22:54

---

### 접근 방식
- 입력 값 중 한 쪽을 정렬해두면 결국 LIS 문제와 비슷하다.
- LIS의 길이를 구하고 원래의 길이에서 이를 빼면 바로 없애야 할 전깃줄의 개수가 나오는 것

---

### 소스코드
- 1116KB, 0ms

```C
#include <stdio.h>

int main(void) {
	int N, Index, WireToLeave, MaxToLeave = 0;
	int Wire[501] = {0,}, CountToLeave[501];
	
	scanf("%d", &N);
	// 정렬 대신 카운팅 배열 사용
	for (int i = 0; i < N; i++) {
		scanf("%d", &Index);
		scanf("%d", &Wire[Index]);
	}

	for (int i = 0; i < 501; i++) {
		if (Wire[i] != 0) { // 카운팅 배열을 사용했으니 입력값이 없는 배열의 index는 통과
			WireToLeave = 0; // 최소 충족 길이
			for (int j = 0; j < i; j++) {
				if (Wire[j] != 0) { // 카운팅 배열을 사용했으니 입력값이 없는 배열의 index는 통과
					if (Wire[j] < Wire[i] && CountToLeave[j] > WireToLeave) { // 앞의 수가 작은 지와 그 index일 때가 지금 최소 충족 길이보다 작은 지 검사
						WireToLeave = CountToLeave[j]; // 최소 충족 길이 변경
					}
				}
			}
			CountToLeave[i] = WireToLeave + 1; // 결과를 배열에 저장
			if (CountToLeave[i] > MaxToLeave)
				MaxToLeave = CountToLeave[i]; // 최대 길이 배열 갱신
		}
	}
	
	printf("%d\n", N-MaxToLeave); // 총 길이에서 남아야 할 길이 빼기
	
	return 0;
} 
```
