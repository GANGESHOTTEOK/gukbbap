
# 백준 1541번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 2월 8일 10시 40분

---

### 접근 방식
- `+`연산자의 우선순위를 `-`의 우선순위보다 높게 둔다.

### 소스코드
- 메모리 : 2020KB
- 시간 : 0ms
```c++
#include <bits/stdc++.h>
using namespace std;
string s;
vector<char*> a;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    getline(cin,s);

    // 입력받은 string을 '-'를 기준으로 분리하여 a에 추가
    char *s_buff = new char[50];
    strcpy(s_buff, s.c_str());
    char *ptr = strtok(s_buff,"-");
    while(ptr != NULL) {
        a.push_back(ptr);
        ptr = strtok(NULL, "-");
    }

    // a에 저장된 덧셈식을 '+'를 기준으로 분리하여 각각의 정수를 합한 값을 v에 추가
    for(int i=0; i<a.size(); i++) {
        int subsum = 0;
        ptr = strtok(a[i],"+");
        while(ptr != NULL) {
            subsum += stoi(ptr);
            ptr = strtok(NULL, "+");
        }
        v.push_back(subsum);
    }

    cout << v[0]-accumulate(v.begin()+1,v.end(),0);
}
```
- `strtok(s_buff,"-")` : `s_buff`에서 `-`를 만나면 그 뒤의 주소를 반환한다.
- `accumulate(v.begin()+1,v.end(),0)` : `v[1]`에서부터 `v[v.size()-1]`에 저장된 값을 모두 합한다.
