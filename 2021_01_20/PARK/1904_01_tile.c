#include <stdio.h>

// 2021.01.15 23:00
// Deli Spice - Confession

// 규칙이 피보나치를 따른다는 것을 알면 쉬운 문제

// N의 수가 1000000 였기 때문에 그냥 피보나치를 구하면 모버플로우 발생
// 출력 할 때가 아닌 처음 구할 때 15746의 나머지를 넣어야 함

// 아래 코드처럼 메모리 관리도 가능
// https://www.acmicpc.net/source/25214617

// https://youtu.be/gX4imVi8R6U?t=2431

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
	//printf("%d\n", NumberOfBinaryTile[N]%15746);
	
	return 0;
}
