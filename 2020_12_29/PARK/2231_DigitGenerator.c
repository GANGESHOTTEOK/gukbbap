#include <stdio.h>

// 2020.12.28 18:29
// 더 간단히 가능 할 듯

// for 안에서 index 수정하면 다음 증감에 변영됨.
// ex) 1 2(+5) 8 9 10 

int main(void) {
	int n = 0, m = 0, temp = 0;
	int num = 0;
	
	scanf("%d", &n);

	for (int i = 1; m == 0 && i <= n; i++) {
		num = i;

		while (num) {
			temp = temp + num%10;
			num = num/10;
		}

		if (n == i+temp)
			m = i;

		temp = 0;
	}
	
	printf("%d\n", m);
	
	return 0;
}

