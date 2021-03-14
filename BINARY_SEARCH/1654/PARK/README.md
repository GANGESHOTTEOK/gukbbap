
# 2021년 3월
# 백준 1654번 [랜선 자르기]
### https://www.acmicpc.net/problem/1654
---

### 문제 해결 날짜 및 시간

- 2021.03.14 12:03

---

### 접근 방식
- 입력 받은 LAN의 길이를 다 더해서 N으로 나눠 최대 길이를 구하고 여기서 시작한다
- 최대 길이부터 각 LAN을 나눠 가며 몫을 구해 이 몫의 총 합이 N보다 크거나 같으면
- LongestLAN을 갱신한다
- 함수로 만들지 않고 10816 문제에서 Upper처럼 while로 풀었다면 더 쉽게 풀었을 듯하다

### 소스코드
- 메모리 : 1156KB
- 시간 : 8ms
```C
#include <stdio.h>

// 그냥 10816 Upper 함수 가져와서 사용했으면 빨리 풀릴 문제
// 함수를 따로 선언하지 않고 while 사용했으면 더 간단 

int K, N, LongestLAN = 0;
long long Sum = 0;
int LAN[10001];

int FindLongestLAN(int NowLAN, int End) {
	int Count = 0;

	for (int j = 0; j < K; j++)
		Count = Count + LAN[j]/NowLAN; // 각 LAN 나눠서 총 개수 구하기 

	if (Count >= N) { // 만든 LAN의 개수가 N보다 크거나 같다면 
		if (LongestLAN < NowLAN) // LAN 최대 길이 갱신 
			LongestLAN = NowLAN;

		// Sum/N이 맞는 경우, (200, 201)이라서 계속 200만 되는 경우 처리 
		if (NowLAN == End || NowLAN == (NowLAN+End)/2) 
			return 0;
		else
			NowLAN = (NowLAN+End)/2; // 중간값 갱신

		FindLongestLAN(NowLAN, End);
	}
	else // 작다는 말은 LAN의 길이를 더 줄여야 한다는 말 
		FindLongestLAN(NowLAN/2, NowLAN); 

	return 0;
}

int main(void) {
	
	scanf("%d %d", &K, &N);
	
	for (int i = 0; i < K; i++) {
		scanf("%d", &LAN[i]);
		Sum = Sum + LAN[i];
	}

	FindLongestLAN(Sum/N, Sum/N);
	
	printf("%d\n", LongestLAN);
	
	return 0;
}
```
