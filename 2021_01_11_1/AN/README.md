
# 백준 1181번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 11일 11시 30분

---

### 접근 방식
- `N`개의 좌표를 `pair<int,string>`로 `vector`에 저장하였다.
- `pair`의 `first`에는 해당 문자열의 길이를, `second`에는 문자열을 저장한다.
- `sort`함수를 사용하여 정렬했다.

### 소스코드
- 메모리 : 4932KB
- 시간 : 60ms
```c++
#include <bits/stdc++.h>

using namespace std;

int cmp(pair<int, string> &a, pair<int, string> &b) {
    if(a.first == b.first) {                            // 문자열의 길이가 같으면
        if (a.second.compare(b.second)>=0) return 0;    // a의 문자열이 b의 문자열보다 뒤에 있거나 같으면
        else return 1;                                  // a의 문자열이 b의 문자열보다 앞에 있으면
    }
    return a.first < b.first;                           // 문자열 길이가 다르면 내림차순 정렬
}

int main() {
    int N;
    cin >> N;
    vector< pair<int, string> > v;
    for(int i=0; i<N; i++) {
        string s;
        cin >> s;
        v.push_back(make_pair(s.length(),s));
    }

    sort(v.begin(), v.end(), cmp);

    // 중복이 있는지 확인하며 출력
    cout << v[0].second << "\n";
    for(int i=1; i<N; i++) {
        if(!v[i].second.compare(v[i-1].second)) continue;
        else cout << v[i].second << "\n";
    }
}
```
- `string`의 `compare`함수를 이용하였다. 
- `compare`함수는 `string`을 인자로 받으며, `s1.compare(s2)`일 때, `s1`이 `s2`보다 사전적으로 앞에 있으면 음수를, 같으면 0을, 뒤에 있으면 양수를 반환한다.