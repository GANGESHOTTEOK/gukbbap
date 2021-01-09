
# 백준 11650번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 7일 
- 메모리 : 3567KB
- 시간 : 116ms

---

```cpp
bool comp(pair<int,int> a,pair<int,int> b){
    // 좌표쌍 a 와 b를 비교

    if(a.first == b.first) 
        return a.second < b.second;
        // x좌표가 같을 경우 y좌표와 비교
    
    else 
        return a.first < b.first;
        // 그렇지 않다면 x좌표로 비교
}

int main(){
    int N,tmpx,tmpy;

    cin >> N;

    vector<pair<int,int>> loc;
    //좌표 x,y를 저장할 수 있는 pair를 원소로 가지는 벡터 loc

    for(int i=0;i<N;i++){
        cin >> tmpx >> tmpy;
        loc.push_back(make_pair(tmpx,tmpy));
        // make_pair 를 통해 좌표를 벡터에 순서대로 입력
    }

    sort(loc.begin(),loc.end(),comp);
    // stl sort를 사용. 위에 선언한 comp함수의 조건대로 loc벡터를 정렬

    for(int i=0;i<N;i++)
        cout << loc[i].first << " " << loc[i].second << "\n";
    //조건에 따라 정렬된 좌표를 출력

    return 0;
}
```

문제에서 `x` , `y` 값을 가진 좌표들을 조건에 따라 정렬해야한다.

처음에는 2차원 배열을 이용하여 풀어볼려고 하였으나, 하다보니 정렬하기에 까다로운 것 같아, `vector` 와 `pair` 를 사용하였다. 

pair class은 2차원 좌표와 같이 2개의 쌍을 가지는 값들을 묶어 `make_pair` 로 대입하거나 `pair.first` `pair.second` 로 참조하여 불러낼 수 있다. `vector<pair<int,int>>` 와 같이 사용하면 `int` 좌표쌍을 원소로 가지는 벡터이다.

`stl sort` 함수를 이용하였고, `comp`함수를 만들어 같을 경우 `y`값을 비교하는 조건을 만들어 내림차순으로 정렬한 후, 조건대로 출력하였다.