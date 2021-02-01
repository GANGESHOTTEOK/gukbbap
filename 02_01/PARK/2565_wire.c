#include <stdio.h>

// 2021.01.26 22:54:51

// 귀찮긴 하지만 
// 구조체에 정렬하고 LIS가 정석인 듯
// https://www.acmicpc.net/source/25258753 

int main(void) {
	int N, Index, WireToLeave, MaxToLeave = 0;
	int Wire[501] = {0,}, CountToLeave[501];
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Index);
		scanf("%d", &Wire[Index]);
	}

	for (int i = 0; i < 501; i++) {
		if (Wire[i] != 0) {
			WireToLeave = 0;
			for (int j = 0; j < i; j++) {
				if (Wire[j] != 0) {
					if (Wire[j] < Wire[i] && CountToLeave[j] > WireToLeave) {
						WireToLeave = CountToLeave[j];
					}
				}
			}
			CountToLeave[i] = WireToLeave + 1;
			if (CountToLeave[i] > MaxToLeave)
				MaxToLeave = CountToLeave[i];
		}
	}
	
	printf("%d\n", N-MaxToLeave);
	
	return 0;
} 
