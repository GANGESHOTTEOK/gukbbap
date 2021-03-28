#include <stdio.h>

// 2021.03.28 11:34
// 1504KB, 20ms 

int N, Index = 0;
int Commend;
int Heap[100001] = {0,};

int Swap(int a, int b) {
	int Temp = Heap[a];
	Heap[a] = Heap[b];
	Heap[b] = Temp;
}

int Push(int Num) { // push binary tree
	Heap[++Index] = Num; // push
	
	int Child = Index; // child node
	int Parent = Index/2; // parent node
	
	while (Child > 1 && Heap[Child] > Heap[Parent]) { // element >= 2, change parent node 
		Swap(Parent, Child);
		
		Child = Parent; // change Child node index. to change nodes
		Parent = Child/2; // change child node index. to change nodes
	}

	return 0;
}

int Pop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = Heap[Parent]; // return value
	Heap[Parent] = Heap[Index--]; // to remove root node
	
	while (Parent*2 <= Index) { // last child node
		if (Heap[Parent] > Heap[Child] && Heap[Parent] > Heap[Child+1]) // nomal binary tree
			break;
		else if (Heap[Child] > Heap[Child+1]) { // change nodes. bigger one of two child node
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
		if (Commend == 0) { // pop
			if (Index == 0)
				printf("0\n");
			else
				printf("%d\n", Pop());
		}
		else // push
			Push(Commend);
	}
	
	return 0;
}
