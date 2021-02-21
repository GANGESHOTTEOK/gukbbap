#include <stdio.h>

// 2021.02.17 22:25

// 다른사람 어떻게 풀었는지 참고하기(바빠서 넘김) 

int PrintOrNot(int Num, int *A) {
	for (int i = Num+1; i < 10; i++) {
		if (A[i] > 0)
			return 0;
	}
	return 1;
}

int main(void) {
	int T, Number, Position, End, Count = 0;
	
	scanf("%d", &T);
	
	for (int i = 0; i < T; i++) {
		scanf("%d %d", &Number, &Position);
		
		int Importance[5051], Degree[10] = {0,};
		
		for (int j = 0; j < Number; j++) {
			scanf("%d", &Importance[j]);
			Degree[Importance[j]] = Degree[Importance[j]] + 1;
		}
		
		End = Number;
		for (int i = 0; i < End; i++) {
			if (PrintOrNot(Importance[i], Degree)) {
				Degree[Importance[i]] = Degree[Importance[i]] - 1;
				Count++;
				if (Position == i) {
					printf("%d\n", Count);
					break;
				}
			}
			else {
				Importance[End++] = Importance[i];
				if (Position == i)
					Position = End-1;
			}
		}
		Count = 0;
	}
	
	return 0;
}
