#include <stdio.h>

// 2021.01.25 23:47

// 답도 없다 진짜
// https://wootool.tistory.com/96
// https://henrynoh.tistory.com/32
// http://melonicedlatte.com/algorithm/2018/07/15/172615.html

int main(void) {
	int N, MinLen = 0, MaxLen = 0;
	int SequenceArr[1001], PartialSeqLen[1001] = {0,};
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &SequenceArr[i]);
	}
	
	for (int i = 0; i < N; i++) {
		MinLen = 0;
		for (int j = 0; j < i; j++) {
			if (SequenceArr[j] < SequenceArr[i] && PartialSeqLen[j] > MinLen) {
				MinLen = PartialSeqLen[j];
			}
		}
		PartialSeqLen[i] = MinLen + 1;
		if (PartialSeqLen[i] > MaxLen)
			MaxLen = PartialSeqLen[i];
	}
	
	printf("%d\n", MaxLen);
	
	return 0;
}
/*
10
1 100 2 3 4 5 6 7 8 9
*/
