#include <stdio.h>

//2020.12.27 22:13
//scanf("%d", &NumList[i]);

int main(void) {
	int n = 0, m = 0;
	int max = 0, sum = 0;
	int NumList[100] = {0,};
	
	scanf("%d %d", &n, &m);
	
	for (int i = 0; i < n; i++)
		scanf("%d", &NumList[i]);

	for (int i = 0; i < n-2; i++) {
		for (int j = i+1; j < n-1; j++) {
			for (int k = j+1; k < n; k++) {
				sum = NumList[i] + NumList[j] + NumList[k];
				if (m >= sum && sum > max)
					max = sum;
			}
		}
	}
	
	printf("%d\n", max);
	
	return 0;
}

