BOJ 15650번 N과 M(2)

문제 접근
---
> - 1부터 N까지 자연수 중에서 중복 없이 M개를 고른 수열
> - 고른 수열은 오름차순이어야 한다.
> - 자연수 N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

지난번 문제 [N과M(1)](http://uzun.dev/2021-01/BOJ15649)와 유사하다.
다만, 고른 수열을 오름차 순으로 출력해야한다는 조건이 추가되었다.

처음은 원


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