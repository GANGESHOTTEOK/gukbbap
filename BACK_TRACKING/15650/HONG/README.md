BOJ 15650번 N과 M(2)

문제 접근
---
> - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
> - 고른 수열은 오름차순이어야 한다.
> - 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

지난번 문제 [N과M(1)](http://uzun.dev/2021-01/BOJ15649)와 유사하다.
다만, 고른 수열을 오름차 순으로, 사전으로 증가하는 순서로 출력해야한다는 조건이 추가되었다.

처음은 N과 M (1)과 똑같이 풀되, 바로 출력하지 않고 조합들을 저장하여 정렬할려고 했다.

하지만, 따로 조합의 구성을 저장해서 메모리를 잡아먹고, 정렬까지 해야하며 구현하기도 지저분 했다.
그래서 그냥 탐색 조건을 바꾸어 순서대로 출력할 수 있도록 하였다.


```cpp

#define MAX 8

int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void dfs(int cnt,int idx){
    if(cnt == M){
        for(int i=0;i<M;i++)
            cout << arr[i]+1 << " ";
        cout << "\n";
        return;
    }

    for(int i = idx;i<N;i++){
        if(visited[i]) continue;
        visited[i] = true;
        arr[cnt] = i;
        dfs(cnt+1,i+1);
        visited[i] = false;
    }
}

int main(){
    cin >> N >> M;

    dfs(0,0 );

    return 0;
}

```

dfs 함수에서 M번의 재귀 호출을 통해 조합을 뽑는다라는 개념은 같지만,
오름차 순으로 출력하기 위해서는 나중에 호출된 dfs 함수에서의 for문에서는 이전의 탐색보다 뒤의 인덱스부터 탐색하여야 할 것이다.

그러므로 dfs 함수에 단계를 표시하여 종료조건에 사용하는 cnt 인자 외에 이전의 호출된 함수의 탐색 조건을 알 수 있는 idx 인자를 추가하였다.

매번 재귀호출 될 때마다 idx+1 이 넘어가므로 호출된 함수의 for문에서는 이전의 idx 보다 1 뒤부터 탐색한다. 
즉, 오름차 순으로만 탐색하여 출력한다.

결과
---
![result](https://i.ibb.co/hFDyhzv/image.png)