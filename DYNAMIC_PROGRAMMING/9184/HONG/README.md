BOJ 9184번 신나는 함수 실행

문제접근
---
아래의 조건을 만족하는 재귀함수 `w(a,b,c)`가 있다.

>if a <= 0 or b <= 0 or c <= 0
>then w(a, b, c) returns: 1
>
>if a > 20 or b > 20 or c > 20, then w(a, b, c) returns:
> then w(a, b, c) returns: w(20, 20, 20)
>
>if a < b and b < c
>then w(a, b, c) returns: w(a, b, c-1) + w(a, b-1, c-1) - w(a, b-1, c)
>
>otherwise 
>it returns: w(a-1, b, c) + w(a-1, b-1, c) + w(a-1, b, c-1) - w(a-1, b-1, c-1)

a,b,c가 주어졌을 때 값을 구할 수 있어야한다.

간단하게 재귀를 돌리면 정말 간단하겠지만, 입력 케이스가 늘어난다면 매번 재귀를 돌려 봐야하므로 메모리제이션하여 불필요한 반복을 줄일 수 있다.



```cpp
#include <iostream>
int main(){
    int W[21][21][21] = {0,};

    for(int i=0;i<21;i++)
        for(int j=0;j<21;j++)
            for(int k=0;k<21;k++){
                if(i<=0 || j<=0 || k<=0) W[i][j][k] = 1;
                else if(i<j && j<k) W[i][j][k] = W[i][j][k-1] + W[i][j-1][k-1] - W[i][j-1][k];
                else W[i][j][k] = W[i-1][j][k] + W[i-1][j-1][k] + W[i-1][j][k-1] - W[i-1][j-1][k-1];
            }

    int result, inp[3];

    while(true){
        cin >> inp[0] >> inp[1] >> inp[2];
        if (inp[0] == -1 && inp[1] == -1 && inp[2] == -1) break;
        else if (inp[0]<=0 || inp[1]<=0 || inp[2]<=0) result = 1;
        else if(inp[0]>20 || inp[1]>20 || inp[2]>20) result = W[20][20][20];
        else result = W[inp[0]][inp[1]][inp[2]];

        cout << "w(" << inp[0] << ", " << inp[1] << ", " << inp[2] << ") = " << result << "\n";
    }

    return 0;
}
```

문제 풀이
---
위에서 말하였듯이 불필요한 반복을 줄이기 위해, 재귀한 값들을 저장할 수 있는 3차원배열 `W[21][21][21]` 를 선언한다.

입력되는 수들의 범위는 (-50,50)이지만 20개의 크기를 지정하였다. 그 이유는
- `w(a,b,c)` 함수의 조건 중에서 a,b,c중 하나라도 20이 넘어가면 w(20,20,20)과 같이 취급한다.
- 마찬가지로 하나라도 0보다 작거나 같다면 1을 리턴한다.
- [50][50][50] 크기의 배열을 선언했다간 메모리 범위를 초과할 것이다.


입력이 주어질 때마다 재귀를 돌려 찾지 않고 3중 for문으로 미리 `W` 3차원 배열을 채워 바로바로 저장된 값을 찾아 출력할 수 있도록 한다.

입력받을 때 20이 넘어가거나 0보다 작은 케이스를 고려하여 출력한다.

결과
---
![result](https://i.ibb.co/KFNN15L/image.pnghttps://i.ibb.co/KFNN15L/image.png)