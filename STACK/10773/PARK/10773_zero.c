#include <stdio.h>

// 2021.02.10 20:39

// 기존에 값이 있는 경우 0으로 바꾸고 갚을 넣는 것보다
// 그냥 값을 넣는 것이 시간을 더 잡아 먹는 듯 

int main(void) {
	int K, Num, Index = 0, Sum = 0;
	int Account[100000];
	
	scanf("%d", &K);
	
	while(K--) {
		scanf("%d", &Num);
		
		if (Num != 0) {
			Account[Index] = Num;
			Sum = Sum + Account[Index];
			Index = Index + 1;
		}
		else {
			Index = Index - 1;
			Sum = Sum - Account[Index];
		}
	}

	printf("%d\n", Sum);
	
	return 0;
}
