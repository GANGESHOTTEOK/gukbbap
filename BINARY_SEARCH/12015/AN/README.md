
# 백준 12015번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 3월 27일

---

### 접근 방식
- LIS의 맨 뒤 원소가 A[i]보다 작거나 같으면 A[i]를 LIS에 삽입한다.
- 그렇지 않으면(LIS.back()>A[i]), LIS에서 A[i] 이상인 값이 처음 나오는 원소(lower_bound)의 인덱스에 A[i]를 삽입한다.

### 소스코드
- 메모리 : 6040KB
- 시간 : 168ms
```c++
#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N), LIS;
    for(int i=0; i<N; i++) cin >> A[i];

    LIS.push_back(A[0]);

    for(int i=0; i<N; i++) {
        
        if(LIS.back() < A[i]) LIS.push_back(A[i]);
        else if(LIS.back() == A[i]) continue;

        else {  // find lower_bound
            int left=0, right=LIS.size(), lower=0;
            while(left<=right) {
                int mid = (left+right)/2;
                if(LIS[mid]<A[i]) left = mid+1;
                else {
                    right = mid-1;
                    lower = mid;
                }
            }
            LIS[lower] = A[i];
        }
    }
    cout << LIS.size();
}
```
