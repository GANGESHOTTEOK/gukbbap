#include <stdio.h>

// 2021.04.06 14:26
// 1896KB, 40ms 

int N, MinIndex = 0, MaxIndex = 0;
int Commend;
int MinHeap[100001] = {0,};
int MaxHeap[100001] = {0,};

int Swap(int a, int b, int *Heap1, int *Heap2) {
	int Temp = Heap1[a];
	Heap1[a] = Heap2[b];
	Heap2[b] = Temp;
}

int MinPush(int Num) {
	MinHeap[++MinIndex] = Num;
	
	int Child = MinIndex;
	int Parent = MinIndex/2;
	
	while (Child > 1 && MinHeap[Child] < MinHeap[Parent]) {
		Swap(Parent, Child, MinHeap, MinHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int MaxPush(int Num) {
	MaxHeap[++MaxIndex] = Num;
	
	int Child = MaxIndex;
	int Parent = MaxIndex/2;
	
	while (Child > 1 && MaxHeap[Child] > MaxHeap[Parent]) {
		Swap(Parent, Child, MaxHeap, MaxHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int MinPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = MinHeap[Parent];
	MinHeap[Parent] = MinHeap[MinIndex--];
	
	while (Parent*2 <= MinIndex) {
		if (MinHeap[Parent] < MinHeap[Child] && MinHeap[Parent] < MinHeap[Child+1])
			break;
		else if (MinHeap[Child] < MinHeap[Child+1]) {
			Swap(Parent, Child, MinHeap, MinHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, MinHeap, MinHeap);

			Parent = Child+1;
			Child = Parent*2;
		}
	}
	
	return PopNum;
}

int MaxPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = MaxHeap[Parent];
	MaxHeap[Parent] = MaxHeap[MaxIndex--];
	
	while (Parent*2 <= MaxIndex) {
		if (MaxHeap[Parent] > MaxHeap[Child] && MaxHeap[Parent] > MaxHeap[Child+1])
			break;
		else if (MaxHeap[Child] > MaxHeap[Child+1]) {
			Swap(Parent, Child, MaxHeap, MaxHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, MaxHeap, MaxHeap);

			Parent = Child+1;
			Child = Parent*2;
		}
	}
	
	return PopNum;
}

int main(void) {
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &Commend);
		if (i&1)
			MinPush(Commend);
		else
			MaxPush(Commend);
		if (MinIndex > 0 && MinHeap[1] < MaxHeap[1]) {
			int MinPopNum = MinPop();
			int MaxPopNum = MaxPop();
			MaxPush(MinPopNum);
			MinPush(MaxPopNum);
		}
		printf("%d\n", MaxHeap[1]);
	}
	
	return 0;
}
