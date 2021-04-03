#include <stdio.h>

// 2021.03.28 00:24

int IncrSequence[1000002] = {0,};
int Sequence[1000001];

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
