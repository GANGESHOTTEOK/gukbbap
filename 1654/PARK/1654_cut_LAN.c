#include <stdio.h>

// 그냥 10816 Upper 함수 가져와서 사용했으면 빨리 풀릴 문제
// 함수를 따로 뺴지않고 while 사용했으면 더 간단 

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
