
# 백준 11651번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 9일

---

### 소스코드
- 메모리 : 3564KB
- 시간 : 124ms

```cpp
int main(){
    int N,tmpx,tmpy;

    cin >> N;

    vector<pair<int,int>> loc;

    for(int i=0;i<N;i++){
        cin >> tmpx >> tmpy;
        loc.push_back(make_pair(tmpx,tmpy));
    }

    sort(loc.begin(),loc.end(),[](pair<int,int> a,pair<int,int> b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;});

    for(auto i:loc)
        cout << i.first << " " << i.second << "\n";

    return 0;
}
```

[#11650 좌표정렬하기](https://github.com/GANGESHOTTEOK/gukbbap/blob/main/2021_01_08/HONG/11650.cpp) 문제와 같다.

그래서 이번에는 lamda 함수와 range-based 순회를 이용하여 코드를 더 간결하게 만들었다.