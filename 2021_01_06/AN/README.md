
# 백준 2108번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 6일 22시 03분

---

### 접근 방식
- N개의 정수를 `vector`에 저장했다. 중앙값, 최빈값, 범위를 구하기 위해 `sort`함수를 이용하여 오름차순으로 정렬했다.
- 평균(`mean`) : STL의 `accumulate`함수를 사용하여 `vector`의 전체 원소의 합을 구한 후 `N`으로 나눴다.
- 중앙값(`median`) : 정렬된 `vector`의 중간 인덱스의 원소가 중앙값이다.
- 최빈값(`mode`) : 정렬된 `vector`의 모든 원소를 순회하며 각 원소의 개수를 카운트한다.
- 범위(`range`) : `vector`의 첫번째 원소와 마지막 원소의 차이다.

### 소스코드
- 메모리 : 5216KB
- 시간 : 76ms
```c++
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());
    // N == v.size()
    double mean = accumulate(v.begin(), v.end(), 0)/(double)N;

    int median = v[N/2];

    int range = v[N-1]-v[0];

    int mode=v[0],max=0, same=1, cnt=1;
    for(int i=1; i<=N; i++) {
        if(v[i-1]==v[i] && i!=N) cnt++; 
        else {
            if(cnt>max) {               // update max, mode.
                max = cnt;
                mode = v[i-1];
                same = 1;
            }
            else if(cnt==max) {         // duplicate cnt.
                if(same==2) {           // it's not second mode.
                    cnt=1;              // reset cnt.
                    continue;
                }
                else if(same==1) {      // it's second mode.
                    same++;
                    mode = v[i-1];
                }
            }
            cnt=1;                      // reset cnt.
        }
    }

    cout << round(mean) << "\n" << median << "\n" << mode << "\n" << range;
}
```
- `mean`은 소수 첫째자리에서 반올림하기 위해 `double`로 선언한 후 `round()`를 사용하여 반올림된 값을 출력하였다.