#include <stdio.h>

int Height[100001];

int FindMinHeight(int Start, int End) {
	int MinHeightIndex = Start;
	
	for (int i = Start; i < End; i++)
		if (Height[i] < Height[MinHeightIndex])
			MinHeightIndex = i;
	
	return MinHeightIndex;
}

long long int CalcMaxArea(int Start, int End) {
	//printf("%d %d\n", Start, End);
	int MinHeightIndex = FindMinHeight(Start, End);
	long long int MaxRectangle = Height[MinHeightIndex] * (End - Start);
	long long int Temp = 0;
	
	if (Start == End)
		return MaxRectangle;
	
	//printf("index %d\n", MinHeightIndex);
	if(Start < MinHeightIndex) {
		Temp = CalcMaxArea(Start, MinHeightIndex);
		if (Temp > MaxRectangle)
			MaxRectangle = Temp;
	}
	
	if(MinHeightIndex < End) {
		Temp = CalcMaxArea(MinHeightIndex+1, End);
		if (Temp > MaxRectangle)
			MaxRectangle = Temp;
	}
	
	return MaxRectangle;
}

int main(void) {
	int N;

	while(1) {
		scanf("%d", &N);
		
		if (N == 0)
			return 0;
		
		for(int i = 0; i < N; i++)
			scanf("%d", &Height[i]);
		
		printf("%lld\n", CalcMaxArea(0, N));
	}
	
	
	return 0;
}
