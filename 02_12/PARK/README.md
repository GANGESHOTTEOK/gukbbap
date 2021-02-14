# 2021년 02월 12일 금요일
# 백준 10773번 제로
### https://www.acmicpc.net/problem/10773

---

### 문제 해결 날짜 및 시간
- 2021.02.10 20:39

---

### 접근방식
- 그냥 0을 입력 받으면 삭제하고 index를 -1 하거나 그냥 index를 -1 하면 되는 것

---

### 소스코드
- 1388KB, 8ms

```C
#include <stdio.h>

// 기존에 값이 있는 경우 0으로 바꾸고 갚을 넣는 것보다
// 그냥 값을 넣는 것이 시간을 더 잡아 먹는 듯 

int main(void) {
	int K, Num, Index = 0, Sum = 0;
	int Account[100000];
	
	scanf("%d", &K);
	
	while(K--) {
		scanf("%d", &Num);
		
		if (Num != 0) { // 0이 아니라면
			Account[Index] = Num; // 그 수를 배열에 넣어요!
			Sum = Sum + Account[Index]; // 합계도 함께 구해요
			Index = Index + 1; // index를 다음으로 넘겨요
		}
		else { // 0이라면
			Index = Index - 1; // index를 -1 해줘요
			Sum = Sum - Account[Index]; // 합계에서도 빼줘요
		}
	}

	printf("%d\n", Sum);
	
	return 0;
}
```
