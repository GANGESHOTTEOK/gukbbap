
# 2021년 01월 29일 금요일
# 백준 11053번 [가장 긴 증가하는 부분 수열]
### https://www.acmicpc.net/problem/11053

---

### 문제 해결 날짜 및 시간
- 2021.01.25 23:47

---
### 접근방식
- 처음에는 그냥 2중 for 사용해서 현재 i의 값보다 j가 크면 그 변수 저장해서 다음 j로 넘어가는 식으로 했지만 (비교 숫자 갱신). 1 100 2 3. 아래의 데이터를 넣으면 오류.
- 결국 인터넷에 LIS 찾아봄. 그 중 시간복잡도가 O(N^2) 방식을 이해하고 채택
- 수열에서 수를 하나씩 빼서 다른 배열에 저장하면서 만들어가는 방식도 있었는데 패스

---
### 소스코드
- 1116KB 0ms

```C
#include <stdio.h>

int main(void) {
	int N, MinLen = 0, MaxLen = 0;
	int SequenceArr[1001], PartialSeqLen[1001] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &SequenceArr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		MinLen = 0;
		for (int j = 0; j < i; j++) { // i 앞까지
			if (SequenceArr[j] < SequenceArr[i] && PartialSeqLen[j] > MinLen) { // i보다 j가 작고 j의 연속 수열의 길이가 더 길면
				MinLen = PartialSeqLen[j]; // 가장 긴 수열의 길이 변경(최소 충족 수열의 길이 갱신)
			}
		}
		PartialSeqLen[i] = MinLen + 1; // memoization. i의 연속 수열의 길이 저장.(+1은 i자신 포함)
		if (PartialSeqLen[i] > MaxLen)
			MaxLen = PartialSeqLen[i]; // 최대 길이 갱신
	}
	
	printf("%d\n", MaxLen);
	
	return 0;
}
```
