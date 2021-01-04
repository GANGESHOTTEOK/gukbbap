
# 백준 2231번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 1월 4일 10시

---

### 접근 방식
- 평균 시간 복잡도가 O(NlogN)인 정렬 알고리즘 세 가지(Heap Sort, Quick Sort, Merge Sort)를 모두 해보았다.

#### Quick Sort
- 메모리 : 8,172KB
- 시간 : 668ms
```C++
#include <bits/stdc++.h>

using namespace std;

int main() {
    int N;
    vector<int> v;
    cin >> N;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    sort(v.begin(), v.end());

    for(auto k:v) cout << k << "\n";
}
```
- STL에서 제공하는 `sort` 함수는 quick sort(퀵 정렬)을 기반으로 한다.
- 최악의 경우 O(N^2)가 될 수도 있다.
- 그러나 일반적으로 평균속도가 가장 빠르다.

#### Heap Sort
- 메모리 : 8,172KB
- 시간 : 772ms
```C++
#include <bits/stdc++.h>

using namespace std;

priority_queue< int, vector<int>, greater<int> > pq;

int main() {
    int N;
    cin >> N;

    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        pq.push(temp); 
    }

    while(!pq.empty()) {
        cout << pq.top() << "\n";
        pq.pop();
    }
}
```
- `priority_queue` (우선순위 큐)를 사용하여 MinHeap으로 정렬하였다.
- `priority_queue`의 `push()`와 `pop()`의 시간복잡도는 O(logN)이다.
- 최악의 경우에도 O(NlogN)을 유지하고 추가적인 배열도 필요하지 않다.

#### Merge Sort
- 메모리 : 14,316KB
- 시간 : 856ms
```C++
#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;

void merge(int B, int E) {      // B : Begin Index, E : End Index
    int mid = (B+E)/2;          // left(B,mid) right(mid+1,E)
    vector<int> sub;
    
    // sorting
    int left=B, right=mid+1, i=B;
    while(left<=mid && right<=E) {
        if(v[left]<v[right]) sub.push_back(v[left++]);
        else sub.push_back(v[right++]);
    }
    while(left<=mid) sub.push_back(v[left++]);
    while(right<=E) sub.push_back(v[right++]);

    copy(sub.begin(), sub.end(), v.begin()+B);
}

void dAq(int B, int E) {        // B : Begin Index, E : End Index
    if(B<E) {
        dAq(B, (B+E)/2);        // left vector
        dAq((B+E)/2+1, E);      // right vector
        merge(B,E);             // merge left,right vectors
    }
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        v.push_back(temp);
    }

    dAq(0,N-1);

    for(auto k:v) cout << k << "\n";
}
```
- Merge Sort는 Divide and Conquer 알고리즘의 대표적인 한 예이다.
- 추가적인 데이터 공간이 필요하다.