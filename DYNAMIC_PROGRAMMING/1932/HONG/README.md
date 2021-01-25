BOJ 1932번 정수 삼각형

문제 접근
---
<a href="https://imgbb.com/"><img src="https://i.ibb.co/kDv7L8t/image.png" alt="image" border="0"></a>

다음과 같이 정수 삼각형이 주어졌을 때 위의 노드에서 아랫층으로 좌우 하나를 골라 내려온다. 이때 고른 수들의 합이 최대인 경로를 찾아야 한다.

형태는 약간 다르지만 [RGB거리](http://www.acmicpc.net/problem/1149) 문제와 비슷하다.

모든 경우의 수를 해보면 좋지만 경우의 수가 기하급수적으로 커서 비효율적이고 시간초과 할 가능성 99%.

그러므로 가장 자리의 값을 제외하고는 이전의 값중 최선의 선택지를 골라 누적합을 구하면 된다.


```cpp
int main(){
    int N,P[500][500] = {0,};
    cin >> N;

    for(int i=0;i<N;i++)
        for(int j=0;j<=i;j++)
            cin >> P[i][j];
     
    for(int i=1;i<N;i++)
        for(int j=0;j<=i;j++){
            if(j==0) P[i][0] += P[i-1][0];
            else if(j==i) P[i][i] += P[i-1][i-1];
            else P[i][j] += max(P[i-1][j-1], P[i-1][j]);
        }

    int max = 0;

    for(int i=0;i<N;i++)
        max = max > P[N-1][i] ? max : P[N-1][i];
    
    cout << max;

    return 0;
}
```

정수삼각형의 누적합을 저장할 수 있는 배열 `P[500][500]` 을 선언한다.

`i`층에서 가장자리 (`j=0`, `j=i`)는 받을 수 있는 이전값이 하나 이므로 누적합을 바로 구해주고,
사이에 위치한 수들은 좌상단 우상단 값을 비교해 큰 값을 더한다.

마지막 층의 누적합들 중 가장 큰 값이 최선의 경로를 선택한 누적합이다.

결과
---
<a href="https://ibb.co/jhRTd7D"><img src="https://i.ibb.co/F6VK9Gz/image.png" alt="image" border="0"></a>