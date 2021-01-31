#include <stdio.h>

// 2021.01.26 21:19

// 11053 ·Î²Ù²¨ ¹öÀü 

int main(void) {
	int N, MaxLen = 0;
	int BitonicSequence[1001];
	int BitonicIncLen[1001] = {0,};
	int BitonicDecLen[1001] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &BitonicSequence[i]);
	}
	
	for (int i = 0; i < N; i++) {
		int IncreaseMin = 0;
		for (int l = 0; l < i; l++) {
			if (BitonicSequence[l] < BitonicSequence[i]) {
				if (IncreaseMin < BitonicIncLen[l]) {
					IncreaseMin = BitonicIncLen[l];
				}
			}
		}
		BitonicIncLen[i] = IncreaseMin + 1;
	}

	for (int i = N-1; i >= 0; i--) {
		int DecreaseMin = 0;
		for (int j = N-1; j > i; j--) {
			if (BitonicSequence[j] < BitonicSequence[i]) {
				if (DecreaseMin < BitonicDecLen[j]) {
					DecreaseMin = BitonicDecLen[j];
				}
			}
		}
		BitonicDecLen[i] = DecreaseMin + 1;		
	}

	for (int i = 0 ; i < N; i++) {
		if (BitonicIncLen[i] + BitonicDecLen[i] > MaxLen)
			MaxLen = BitonicIncLen[i] + BitonicDecLen[i];
	}
	
	printf("%d\n", MaxLen-1);
	
	return 0;
}
/*
¹Ý·Ê
1
1
 
10
9 8 6 2 3 5 4 10 1 7
*/
