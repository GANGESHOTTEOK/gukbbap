
### 문제 접근

1부터 N까지 자연수 중에서 중복 없이 M개를 골라 수열을 만들어야한다.

N개 중 M개의 원소를 골르는 경우의 수를 구하는 조합의 문제이므로 dfs 탐색에 여러 조건을 더해 구할 것이라 생각해 볼 수 있다. 



```cpp
#define MAX 8

int N,M;
int arr[MAX] = {0,};
bool visited[MAX] = {0,};

void dfs(int cnt){
    if(cnt == M){
        for(int i=0;i<M;i++)
            cout << arr[i]+1 << " ";
        cout << "\n";
        return;
    }

    for(int i=0;i<N;i++){
        if(visited[i]) continue;
        visited[i] = true;
        arr[cnt] = i;
        dfs(cnt+1);
        visited[i] = false;
    }
}

int main(){
    cin >> N >> M;

    dfs(0);

    return 0;
}
```

풀이
---
for문을 돌려 탐색하면서 방문하지 않은 원소에 방문하여 원소를 arr에 임시저장하고, visited bool배열에 방문여부를 표시한다.

한 조합을 구할 때 M번의 반복 (->재귀)가 필요하므로 dfs 함수에 정수 cnt 인자를 받아 다시 호출할 때 마다 ++된 값으로 호출해준다. 

만약 cnt 가 M과 같아진다면 M+1번 호출 되었다는 것이고, 더 이상 arr 배열에 원소를 뽑지않고, 출력한 다음 리턴시켜서 전 단계로 돌아가 탐색을 재개한다.

결과
---
![result](https://i.ibb.co/cbXfN0H/image.png)

