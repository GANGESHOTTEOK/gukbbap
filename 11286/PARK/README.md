
# 백준 11286번 문제
https://www.acmicpc.net/problem/11286
---

### 문제 해결 날짜 및 시간

- 2021.04.06 14:56

---

### 접근 방식
- 처음에는 최소힙에 조건문을 바꿔 구현하려 했으나 꼬여서 '1655 중간값 말하기'와 비슷한 방식으로 해결
- 음수를 저장할 배열과 양수를 저장할 배열을 선언한다
- 음수는 최대힙으로 양수는 최소힙으로 구성한다
- 0이 입력될 때마다 최대힙의 root와 최소힙의 root의 절댓값을 비교하고 작은 값을 pop후 출력
- 만약 최대힙의 root와 최소힙의 root의 절댓값이 같을 경우 최대힙의 root를 pop후 출력

- 구조체를 활용하는 것이 편한듯. 절대값과 원래값 둘 다로 구성해서
---

### 소스코드
- 메모리 : 1896KB
- 시간 : 24ms
```C
#include <stdio.h>
#include <stdlib.h>

// 다른 사람들은 구조체 사용해서 구했음. 절대값과 원래값을 배열에 같이 넣어서 

int N, PlusIndex = 0, MinusIndex = 0;
int Commend;
int PlusHeap[100001] = {0,};
int MinusHeap[100001] = {0,};

int Swap(int a, int b, int *Heap1, int *Heap2) {
	int Temp = Heap1[a];
	Heap1[a] = Heap2[b];
	Heap2[b] = Temp;
}

int PlusPush(int Num) {
	PlusHeap[++PlusIndex] = Num;
	
	int Child = PlusIndex;
	int Parent = PlusIndex/2;
	
	while (Child > 1 && PlusHeap[Child] < PlusHeap[Parent]) {
		Swap(Parent, Child, PlusHeap, PlusHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int MinusPush(int Num) {
	MinusHeap[++MinusIndex] = Num;
	
	int Child = MinusIndex;
	int Parent = MinusIndex/2;
	
	while (Child > 1 && MinusHeap[Child] > MinusHeap[Parent]) {
		Swap(Parent, Child, MinusHeap, MinusHeap);
		
		Child = Parent;
		Parent = Child/2;
	}
	
	return 0;
}

int PlusPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = PlusHeap[Parent];
	PlusHeap[Parent] = PlusHeap[PlusIndex--];
	
	while (Parent*2 <= PlusIndex) {
		if (PlusHeap[Parent] < PlusHeap[Child] && PlusHeap[Parent] < PlusHeap[Child+1])
			break;
		else if (PlusHeap[Child] < PlusHeap[Child+1]) {
			Swap(Parent, Child, PlusHeap, PlusHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, PlusHeap, PlusHeap);

			Parent = Child+1;
			Child = Parent*2;
		}
	}
	
	return PopNum;
}

int MinusPop() {
	int Parent = 1;
	int Child = Parent*2;
	int PopNum = MinusHeap[Parent];
	MinusHeap[Parent] = MinusHeap[MinusIndex--];
	
	while (Parent*2 <= MinusIndex) {
		if (MinusHeap[Parent] > MinusHeap[Child] && MinusHeap[Parent] > MinusHeap[Child+1])
			break;
		else if (MinusHeap[Child] > MinusHeap[Child+1]) {
			Swap(Parent, Child, MinusHeap, MinusHeap);

			Parent = Child;
			Child = Parent*2;
		}
		else {
			Swap(Parent, Child+1, MinusHeap, MinusHeap);

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
		
		if (Commend < 0)
			MinusPush(Commend);
		else if (Commend > 0)
			PlusPush(Commend);
		else {
			if (MinusIndex > 0 && PlusIndex > 0) {
				if (abs(MinusHeap[1]) <= PlusHeap[1])
					printf("%d\n", MinusPop());
				else
					printf("%d\n", PlusPop());
			}
			else if (MinusIndex > 0 || PlusIndex > 0) {
				if (MinusIndex > 0)
					printf("%d\n", MinusPop());
				else
					printf("%d\n", PlusPop());
			}
			else
				printf("0\n");
		}
	}
	
	return 0;
}

```