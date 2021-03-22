#include <stdio.h>
#include <stdlib.h>

int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;

    if (num1 < num2)
        return -1;
    
    if (num1 > num2)
        return 1;
    
    return 0;
}

int main(void) {
	int N, C, Ans, NowLen = 0, MaxLen = 0, PreHome = 0;
	int Home[200001];
	
	scanf("%d %d", &N, &C);
	
	for (int i = 0; i < N; i++)
		scanf("%d", &Home[i]);
	
	qsort(Home, N, sizeof(int), compare);
	
	NowLen = 1;
	//MaxLen = (Home[N-1] - Home[0] + 1)/C;
	MaxLen = Home[N-1] - Home[0];
	
	while(NowLen <= MaxLen) {
		int Mid = (NowLen+MaxLen)/2;
		int PreHome = Home[0];
		int Count = 1;
		
		for (int i = 1; i < N; i++) {
			if (Mid <= (Home[i] - PreHome)) {
				PreHome = Home[i];
				Count++;
			}
		}
		
		if (Count >= C) {
			NowLen = Mid+1;
			Ans = Mid;
		}
		else
			MaxLen = Mid-1;
		
	}
	
	printf("%d\n", Ans);
	
	return 0;
}
