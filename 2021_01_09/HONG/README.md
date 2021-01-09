
# 백준 11651번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 9일

---

### 소스코드
- 메모리 : 3564KB
- 시간 : 124ms

```cpp
bool comp(pair<int,int> a,pair<int,int> b){
    if(a.second == b.second) return a.first < b.first;
    else return a.second < b.second;
}

int main(){
    int N,tmpx,tmpy;

    cin >> N;

    vector<pair<int,int>> loc;

    for(int i=0;i<N;i++){
        cin >> tmpx >> tmpy;
        loc.push_back(make_pair(tmpx,tmpy));
    }

    sort(loc.begin(),loc.end(),comp);

    for(int i=0;i<N;i++)
        cout << loc[i].first << " " << loc[i].second << "\n";

    return 0;
}
```

[#11650 좌표정렬하기](https://github.com/GANGESHOTTEOK/gukbbap/blob/main/2021_01_08/HONG/11650.cpp) 문제와 같다.