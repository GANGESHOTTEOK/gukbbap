#include <stdio.h>

// 2021.03.28 11:50
// 1504KB, 20ms 

int N, Index = 0;
int Commend;
int Heap[100001] = {0,};

int Swap(int a, int b) {
	int Temp = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = Temp;
}

int Push(int Num) {
	Heap[++Index] = Num;
	
	int Child = Index;
	int Parent = Index/2;
	
	while (Child > 1 && Heap[Child] < Heap[Parent]) {
		Swap(Parent, Child);
		
		Child = Parent;
		Parent = Child/2;
	}

	return 0;
}

int Pop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = Heap[Parent];
	Heap[Parent] = Heap[Index--];
	
	while (Parent*2 <= Index) {
		if (Heap[Parent] < Heap[Child] && Heap[Parent] < Heap[Child+1])
			break;
		else if (Heap[Child] < Heap[Child+1]) {
			Swap(Parent, Child);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1);

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
		if (Commend == 0) {
			if (Index == 0)
				printf("0\n");
			else
				printf("%d\n", Pop());
		}
		else
			Push(Commend);
	}
	
	return 0;
}
