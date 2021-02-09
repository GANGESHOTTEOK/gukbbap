BOJ 11047번 동전 0

<img src="https://i.ibb.co/7jZgxMx/image.png" alt="image" border="0">

문제 접근
---
오름차 순으로 N 종류의 동전이 주어지면, 이를 조합하여 K원을 만드는 최소의 갯수를 구한다.

간단하게 생각해 보았을 때 65000 원이 있다고 치자.
- 천원 65장 보다는 오천원 12장이,
- 오천원 짜리 12장 보다는 만원짜리 6장이,
- 만원 짜리 6장 보다는 5만원짜리 1장을,

사용하였을 떄 사용하는 지폐가 적다.

그러므로 큰 단위를 가진 동전을 우선적으로 최대한 금액을 채우고, 나머지를 그 다음으로 큰 단위의 동전으로 채우는 식의 순서를 가진 알고리즘을 짜면된다.

문제 풀이
---
```cpp
int main(){
    int N,K,sum=0;
    int A[10];
    cin >> N >> K;
    for(int i=0;i<N;i++) cin >> A[i];

    for(int i=N-1;i>=0;i--){
        sum += K / A[i];
        K %= A[i];
    }

    cout << sum;
    return 0;
}
```
동전배열을 탐색하며,

`K/A[i]` 현재 가장 큰 동전을 꽉 채운 갯수를 `sum`에 누적
`A[i]` 동전으로 채운 금액을 제하면 `K%A[i]`

결과
---
<img src="https://i.ibb.co/gFCbc50/image.png" alt="image" border="0">