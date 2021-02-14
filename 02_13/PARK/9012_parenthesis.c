#include <stdio.h>

// 2021.02.10 21:44

int main(void) {
	int T, Left = 0, Right = 0, VPS = 0;
	char Parenthesis[51];
	
	scanf("%d", &T);
	
	while (T--) {
		scanf("%s", &Parenthesis);
		for (int i = 0; Parenthesis[i] != '\0'; i++) {
			if (Parenthesis[i] == '(')
				VPS = VPS + 1;
			else
				VPS = VPS - 1;
			
			if (VPS < 0)
				break;
		}
		
		printf("%s\n", (VPS==0) ? "YES" : "NO");
		
		VPS = 0;
	}
	
	return 0;
} 
