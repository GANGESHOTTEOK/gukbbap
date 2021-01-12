#include <iostream>
using namespace std;
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
        arr[cnt] = i;
        dfs(cnt+1,i);
    }
}

int main(){
    cin >> N >> M;

    dfs(0,0);

    return 0;
}
