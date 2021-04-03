
# 백준 12015번 문제
https://www.acmicpc.net/problem/12015
---

### 문제 해결 날짜 및 시간

- 2021.03.28 00:24

---

### 접근 방식
- LIS를 만들 배열을 선언한다
- 입력받은 수가 LIS의 마지막 수보다 큰지 작은지 판단한다
- 크면 LIS의 마지막에 넣고
- 작으면 LIS의 수 중에서 입력 받은 수 보다 첫번째로 큰 수를 입력 받은 수로 바꾼다
- 최종 LIS 배열이 정답 LIS의 값과 다를 수 있는데 이는 상관없다
- 이유는 과정을 모두 거치는 중의 배열이기 때문이다.
- 현재 index까지의 LIS배열과 새로운 LIS배열을 만드는 과정이 섞인 배열이기 때문이다.
- 따라서 최종 LIS와 정답 LIS가 달라도 Index가 정답이 되는 것이다.

### 소스코드
- 메모리 : 8928KB
- 시간 : 220ms
```C
#include <stdio.h>

int IncrSequence[1000002] = {0,};
int Sequence[1000001]; // 이건 선언할 필요 없었다.

// find Lower number index that is biger than Target
int LowerBound(int Start, int End, int Target) {
	while(Start < End) {
		int Mid = (Start+End)/2;
		if (Target <= IncrSequence[Mid])
			End = Mid;
		else
			Start = Mid + 1;
	}
	return End;
}

int main(void) {
	int N, Index = 0;

	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Sequence[i]);
		if (IncrSequence[Index] < Sequence[i]) { // check back
			Index = Index + 1;
			IncrSequence[Index] = Sequence[i]; // push
		}
		else {
			int LowIndex = LowerBound(0, Index, Sequence[i]); // find LowerIndex
			IncrSequence[LowIndex] = Sequence[i]; // change value
		}
	}
	
	printf("%d\n", Index);
	
	return 0;
}
```
