BOJ 11053번 가장 긴 증가하는 부분 수열
<img src="https://i.ibb.co/7KkwjXg/image.png" alt="image" border="0">

문제 접근
---
주어지는 수열의 가장 긴 부분 수열의 길이를 출력하는 문제이다.

부분 수열이란, 
> 주어진 수열의 **일부 항**을 원래 **순서대로** 나열하여 얻을 수 있는 수열

예를 들면 A = {10, 20, 10, 30, 20, 50} 가 주어졌을 때,
순서를 유지하는 {10,20} {20,10,50} {20,30}과 같은 부분적인 집합들이다.

그중 A에서 증가하면서 가장 큰 수열은 {10,20,30,50} 이므로 길이 4를 출력하는 것이다.

#### 1. 완전탐색의 경우

완전 탐색의 경우를 생각해보자.

모든 경우의 부분수열을 찾아야 하므로, 모든 원소가 시작점으로 잡아 볼 수 있다.
시작 점을 잡고, 자신보다 높은 인덱스를 순회하며 해당 값보다 큰 인덱스의 수들을 따로 저장하여 수열을 만든다.

그리고는 저장한 수열에서 다시 시작 점을 잡고, 배열을 순회하며 자신보다 큰 값을 찾는 식의 재귀호출 될 때마다 1식 더해준다면, 첫 for문에서 잡은 원소를 시작 점으로 잡았을 때의 최장증가수열을 알 수 있다.

이를 pesudo 코드로 짜보면
```cpp
function lis(arr)
    maxlen = 0

    if(arr.empty) 
        return 0;

    for(i = 0 ~ arr.size)
        temp = 0

        for(j = i+1 ~ arr.size)
            if(arr[i] < arr[j])
                temp.push_back(arr[j])

        maxlen = max(maxlen, lis(arr) + 1)

    return maxlen
```

`i`를 시작점으로, `j`는 수열을 돌면서 `i`보다 뒤에 있고, 값이 큰 원소를 `temp`에 저장한다.

모아진 `temp`수열은 기존 `i`를 앞에 둔 부분수열의, `i+1`번째 원소가 될 수 있는 수들의 집합이므로 `temp`를 재귀. 결국 base case인 `arr.empty` 에 닿으면 올라간다.

`maxlen`에 가장 큰 증가부분수열을 저장 후 리턴

---
확실하지만, 모든 수에 대해 모든 다른 수를 비교해가며 재귀해나가기 때문에 엄청나게 비효율적일 것이다. 찾아보니 시간 복잡도는 O(2^N)인 미친 성능을 보여준다.

#### 2. 동적계획법 DP를 이용한 경우

- **Memoization - Topdown**

완전탐색의 아이디어에서 힌트를 얻어 메모이제이션을 이용한 동적계획법을 사용하여 lis 함수를 세워 볼 수 있다.

완전 탐색에서 i는 배열을 순회하며 i번째 수의 값보다 큰들을 모아, 재귀를 돌리고 가장 큰 값을 찾아 리턴한다.

반복문을 돌며 재귀 호출되며, `lis(i)`는
**i번째부터 N-1까지의 최장 증가수열의 길이**라고 볼 수 있다.

생각해보면 완전탐색을 하며 같은 값의 인자를 가진 함수를 여러번 호출하는 것을 하므로, 불필요한 중복을 막기 위해 각 원소의 lis 값을 저장한다.

```cpp
// memoization을 위한 cache배열은 -1로 초기화
function lis(int i)
    if (cache[i] != -1) 
        return cache[i]

    for (nxt = i+1 ~ N) 
        if (num[i] < num[nxt]) 
            maxlen = max(maxlen, lis(nxt)+1)
    
    cache[i] = maxlen
    return maxlen
}
```
완전 탐색과 유사하지만, `cache`에 `i`부터 `N-1`까지의 lis를 저장함으로서
base case인 `cache[i] != -1`으로 이미 구한 lis를 재귀하지 않고 바로 리턴한다.

- **Tabulation - Bottomup**
  
위의 재귀를 이용하여 cache에 저장하는 방법과 유사하다.

`memoization`이 필요할 때 마다 재귀호출하여 연산한 결과를 저장해놓고 쓰는 방법이라면,

`tabulation`은 dp 테이블을 만들어 모든 원소에 대해 연산한 결과를 이용하여 다음 연산 때 계산하는, 밑에서 부터 차곡 차곡 쌓아 올리는 방법이다.

```cpp
// tabulation 위한 cache배열은 -1로 초기화
function lis(int N){
    for(i = 0 ~ N)

        for(j = 0 ~ i)
            if(arr[i] > arr[j] and table[i] < table[j]+1) 
                table[i] = table[j]+1

        maxlen = max(maxlen, table[i])
    
    return maxlen
}
```

여기서 `lis(i)`의 정의는
**0번째 원소부터 i-1번째 원소까지의 최장 증가수열의 길이**로 재귀를 이용한 방법과 반대이다.

한 원소(`i`)에 대해 앞의 원소들(`j`)을 돌며 i번째 수의 값보다 작고, lis 가 +1했을 때 큰 수를 테이블에 저장하고, 가장 큰 길이를 리턴한다.

---
두 방법 모두 `O(N^2)`의 실행 속도를 가진다.

완전 탐색과 dp를 이용한 방법 외에도 이분탐색, 세그먼트 트리 등 더 빠른 실행속도를 가지는 다양한 알고리즘들이 있다고 하였지만, dp를 공부 중 이기에 일단은 dp로 풀었다.

문제 풀이
---
```cpp
int main(){
    int arr[1000], dp[1000] = {0,};
    int N, Max = 0;

    cin >> N;
    for(int i=0;i<N;i++) cin >> arr[i];

    for(int i=0;i<N;i++){
        if(!dp[i]) dp[i]++;
        for(int j=0;j<i;j++)
            if(arr[i] > arr[j] && dp[i] < dp[j]+1) 
                dp[i] = dp[j]+1;
        Max = Max > dp[i] ? Max : dp[i];
    }
    cout << Max;
    
    return 0;
}
```

푸는 건 반복 문을 돌려 Bottomup 방식으로 풀었다.


결과
---
<img src="https://i.ibb.co/Bcy1xts/image.png" alt="image" border="0">


