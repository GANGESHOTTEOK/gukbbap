
# 2021년 3월
# 백준 1300번 [K번째 수]
### https://www.acmicpc.net/problem/1300
---

### 문제 해결 날짜 및 시간

- 2021.03.22 18:39

---

### 접근 방식
- 찾고자 하는 수를 범위로 두고 이분탐색
- 배열의 값이 곧 구구단이라는 걸 이용해서 2중 for문을 사용하지 않고 mid/i로 시간 

### 소스코드
- 메모리 : 1116KB
- 시간 : 12ms
```C
#include <stdio.h>

int Min(const int a, const int b) {
	return (a < b ? a : b);
}

int main(void) {
	int N, K, Start = 1, End = 0, Ans = 0;
	
	scanf("%d %d", &N, &K);
	
	K = (K > 1000000000) ? 1000000000 : K; // 문제 조건 충족. 필요없는듯?
	
	End = K; // End 갱신, K번째 수는 K를 넘을 수 
	
	while(Start <= End) { // Start와 End는 K 번째 수의 범위
		int Mid = (Start+End)/2; // K 번째 수의 후보 정의
		int Count = 0; // Mid의 수가 K 번째가 맞는지 확인하는 변수
		/*
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int Num = ((i+1)*(j+1)); // 시간 초과 코드
				if (Num <= Mid)
					Count++;
				else
					break;
			}
		}
		*/
		
		for (int i = 1; i <= N; i++)
			Count = Count + Min(N, Mid/i); // 가장 중요한 부분
		// i*j는 결국 구구단. 따라서 Mid/i를 하면 i번째 행의 Mid보다 작은 수의 개수가 나오는 것
		// 여기서 Min(N, Mid/i)를 하는 이유는 5*5 행렬에서 만약 찾고자 하는 수가 18이라면
		// 3행에서 Mid/i는 6이 되니까 5를 넘어가 개수가 1개 더 추가되는 것
		
		if (Count < K)
			Start = Mid+1; // 작은 수를 Mid로 선택했으니 Start 갱신
		else{ // Count >= K
			End = Mid-1; // 큰 수를 Mid로 선택했으니 End 갱신
			Ans = Mid; // Count >= K라는 것은 찾았다는 것. 답 갱신
		}
		
	}
	
	printf("%d\n", Ans);
	
	return 0;
}
```
