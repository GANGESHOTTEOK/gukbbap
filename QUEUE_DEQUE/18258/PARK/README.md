
# 백준 18258번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.16 22:37

---

### 접근 방식
- 문제 그대로 구현

### 소스코드
- 메모리 : 8928KB
- 시간 : 520ms
```C
#include <stdio.h>
#include <string.h>

int Queue[2000001], Index = -1, StartIndex = -1;

int Push(int a) {
	Queue[++Index] = a;
}

int Pop(void) {
	if (Index > StartIndex) {
		printf("%d\n", Queue[++StartIndex]);
	}
	else
		printf("-1\n");
}

int front(void) {
	if (Index == StartIndex)
		printf("-1\n");
	else
		printf("%d\n", Queue[StartIndex+1]);
}

int main(void) {
	int N, PushNum;
	char Command[7];
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", Command);
		if (strcmp(Command, "push") == 0) {
			scanf("%d", &PushNum);
			Push(PushNum);
		}
		else if (strcmp(Command, "pop") == 0)
			Pop();
		else if (strcmp(Command, "size") == 0)
			printf("%d\n", Index-StartIndex);
		else if (strcmp(Command, "empty") == 0)
			printf("%d\n", (Index-StartIndex == 0) ? 1 : 0);
		else if (strcmp(Command, "front") == 0)
			front();
		else
			printf("%d\n", (Index == StartIndex) ? -1 : Queue[Index]);
	}
	
	return 0;
}
```
