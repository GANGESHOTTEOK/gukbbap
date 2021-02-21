#include <stdio.h>
#include <string.h>

// 2021.02.15 17:25

// 산술적으로 풀다가 ([)] 처리 못해서 포기 

char String[101], Stack[101] = {0,};

int main(void) {
	int Index = -1;
	
	while(1) {
		gets(String);

		if (String[0] == '.')
			break;

		for (int i = 0; String[i] != '.'; i++) {
			if (String[i] == '(') {
				Index = Index + 1;
				Stack[Index] = '(';
			}
			else if (String[i] == ')') {
				if (Stack[Index] == '(' && Index > -1) {
					Stack[Index] = '\0';
					Index = Index - 1;
				}
				else {
					Index = 0;
					break;
				}
			}
			else if (String[i] == '[') {
				Index = Index + 1;
				Stack[Index] = '[';
			}
			else if (String[i] == ']') {
				if (Stack[Index] == '[' && Index > -1) {
					Stack[Index] = '\0';
					Index = Index - 1;
				}
				else {
					Index = 0;
					break;
				}
			}
		}
		printf("%s\n", (Index == -1) ? "yes" : "no");
		Index = -1;
	}
	
	return 0;
}
