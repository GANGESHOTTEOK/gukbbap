
# 백준 1003번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 18일 13시 20분

---

### 접근 방식
- 시간을 줄이기 위해 메모이제이션을 사용하였다. 

### 소스코드
- 메모리 : 2052KB
- 시간 : 444ms
```c++
#include <bits/stdc++.h>

using namespace std;

int m[21][21][21];

int w(int a, int b, int c) {
    if(a<=0 || b<=0 || c<=0) 
        return 1;

    if(a>20 || b>20 || c>20) 
        return w(20,20,20);

    if(m[a][b][c]) 
        return m[a][b][c];

    if(a<b && b<c) 
        return m[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);

    return m[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1, b, c-1) - w(a-1,b-1,c-1);
} 

int main() {
    int x,y,z;

    while(1) {
        cin >> x >> y >> z;
        if(x==-1 && y==-1 && z==-1) break;

        cout << "w(" << x << ", " << y << ", " << z << ") = " << w(x,y,z) << "\n";
    }
}
```