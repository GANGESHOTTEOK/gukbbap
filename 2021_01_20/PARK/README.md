
# 2021년 01월 20일 수요일
# 백준 1904번 [01타일]
### https://www.acmicpc.net/problem/1904

---

### 문제 해결 날짜 및 시간
- 2021.01.11 23:12

---

### 접근 방식
- 사용할 수 있는 타일은 00과 1이다. 즉, 00으로 시작했을 때와 1로 시작했을 때로 나누어 볼 수 있다.
- 1로 시작했다면 N 자리 중 1개를 사용했고 나머지 N-1개의 자리를 채워야 한다.
- 00으로 시작했다면 N 자리 중 2개를 사용했고 나머지 N-2개의 자리를 채워야 한다.
- 이는 N-1개, N-2개를 구할 때도 동일하게 적용 된다.
- 이걸 점화식으로 표현하면 N자리 경우의 수 = N-1자리 경우의 수 + N-2자리 경우의 수.로 표현 가능하다
- 피보나치와 같은 문제가 되는 것.

---

### 소스코드
- 5020KB, 4ms
```C
#include <stdio.h>

// N의 수가 1000000 였기 때문에 그냥 피보나치를 구하면 모버플로우 발생
// 출력 할 때가 아닌 처음 구할 때 15746의 나머지를 넣어야 함

int NumberOfBinaryTile[1000002];

int main(void) {
	int N;
	
	NumberOfBinaryTile[1] = 1;
	NumberOfBinaryTile[2] = 2;
	
	for (int i = 3; i < 1000001; i++) { // 피보나치 수열 구하기 
		NumberOfBinaryTile[i] = (NumberOfBinaryTile[i-1] + NumberOfBinaryTile[i-2])%15746;
	}
	
	scanf("%d", &N);
	printf("%d\n", NumberOfBinaryTile[N]);
	
	return 0;
}
```
