#include <stdio.h>

// 2020.12.29 20:54
// 2231_Digit_Generator와 비슷한 듯 
// 첫 코드는 6666부터 count를 2개씩 올려서 틀렸던 것
// 이 코드에서는 원하는 수(*666*)를 하나만 체크하고 반복문을 나가는게 포인트

int main(void) {
	int n = 0, temp = 0, count = 0;
	
	scanf("%d", &n);
	
	for (int i = 666; ;i++) {
		temp = i;
		while (temp) {
			if (temp%1000 == 666) {
				count = count + 1;
			}
			temp = temp/10;
		}
		
		if (count)
			n = n - 1;
			
		if (!n) {
			printf("%d\n", i);
			return 0;
		}
		count = 0; 
	}
	
	return 0;
}
