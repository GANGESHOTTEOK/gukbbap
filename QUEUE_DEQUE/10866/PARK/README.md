
# 백준 10866번 문제

---

### 문제 해결 날짜 및 시간

- 2021.02.17 23:34

---

### 접근 방식
- 문제 그대로 구현. 대신 배열의 크기를 2배로 선언해서 사용

### 소스코드
- 메모리 : 1192KB
- 시간 : 4ms
```C
#include <stdio.h>
#include <string.h>

int Num[20002] = {0,}, Size = 0, Front = 10000, Back = 10000;

int PushBack(int a) {
	Num[Back++] = a;
}

int PushFront(int b) {
	Num[--Front] = b;
}

int PopFront(void) {
	if (Size == 0)
		printf("-1\n");
	else
		printf("%d\n", Num[Front++]);
}

int PopBack(void) {
	if (Size == 0)
		printf("-1\n");
	else
		printf("%d\n", Num[--Back]);
}

int main(void) {
	int N, PushNum;
	char Command[20];
	
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%s", &Command);
		
		if (strcmp(Command, "push_back") == 0) {
			scanf("%d", &PushNum);
			PushBack(PushNum);
			Size++;
		}
		else if (strcmp(Command, "push_front") == 0) {
			scanf("%d", &PushNum);
			PushFront(PushNum);
			Size++;
		}
		else if (strcmp(Command, "pop_front") == 0) {
			PopFront();
			if (Size != 0)
				Size--;
		}
		else if (strcmp(Command, "pop_back") == 0) {
			PopBack();
			if (Size != 0)
				Size--;
		}
		else if (strcmp(Command, "size") == 0) {
			printf("%d\n", Size);
		}
		else if (strcmp(Command, "empty") == 0) {
			printf("%d\n", (Size == 0) ? 1 : 0);
		}
		else if (strcmp(Command, "front") == 0) {
			printf("%d\n", (Size == 0) ? -1 : Num[Front]);
		}
		else {
			printf("%d\n", (Size == 0) ? -1 : Num[Back-1]);
		}
	}
	
	return 0;
}
```
