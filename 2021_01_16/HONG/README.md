
# 백준 14889번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 16일 

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 32ms

---

### 접근 방식
```cpp

    #include <iostream>
    #include <cmath>
    using namespace std;

    int N, min_diff = 2147483647;
    bool visited[20] = {false,};
    int S[20][20], team[2][10];

    int calculator(int *team){
        int acc = 0;
        // 누적하여 합산할 변수이다.

        for(int i=0;i<N/2;i++)
            for(int j=0;j<N/2;j++){
                if(i==j) continue;
                // 중복 없이
                acc += S[team[i]][team[j]];
                // 누적 acc 에 능력치 합산
            }

        return acc;
    }

    void cbn(int cnt,int cur){
        // N명의 사람들 중에 N/2명의 팀원을 중복없이 순서 고려 없이 골라야 하므로 dfs 돌린다.

        if (cnt == N/2){
            // team[0] N/2명을 모두 뽑고 나면

            for(int i=0,j=0; i<N; i++)
                if (!visited[i]) team[1][j++] = i;
            // 남은 false값을 가진 visited의 인덱스 들은 모두 team[1]의 팀원이라고 볼 수 있다.

            int cur_diff = abs( calculator(team[0]) - calculator(team[1]) );
            // cur_diff 는 현 조합에서 team[0]와 team[1]의 능력치 합산 차 이다.

            min_diff = cur_diff > min_diff ? min_diff : cur_diff;
            // min_diff 와 비교하여 최저차를 찾는다.
            
            return;
        }
        for (int i = cur+1; i < N; i++){
            // 순서를 고려 하므로 이전의 i값을 알 필요가 있다. 중복도 없으므로 i는 이전의 i값 (cur)보다 1많게 출발한다.

            if (visited[i]) continue;
            // 이미 고른 팀원은 패스

            visited[i] = true;
            team[0][cnt] = i;
            // 팀원을 고른다.

            cbn(cnt + 1,i); 
            //다음 팀원을 고르러 재귀호출

            visited[i] = false;
        }
    }

    int main(){
        cin >> N;

        for(int i=0;i<N;i++) 
            for(int j=0;j<N;j++) 
                cin >> S[i][j];
        // 배열 S 에 배열을 저장한다.

        cbn(0,0);

        cout << min_diff;

        return 0;
    }

```

`스타트팀`과 `링크팀`으로 나누어 능력치를 비교한다.

각 팀에서, 서로 같은 팀일때의 능력치를 합산하여 모두 더하면 팀의 능력치이다. 
팀에 1,2,3이 있다면 S12 + S21 + S23 + S32 + S13 + S31 이다. 즉 팀에서 순서고려 중복없이 2명을 뽑는 경우의 능력치 수를 모두 합친 것과 같다.

일단은 순서를 고려하지 않고 중복없이 팀원을 골라야 할 것이다. 

조합하기 위하여 `cbn` 함수를 통해 `dfs`를 돌린다. `cnt` 인자를 받아 N/2개를 `team` 배열의 넣는데, 중복이 없고 순서를 고려하지 않으므로 `cbn` 함수에서 완전 탐색을 할때 조건이 필요하다.

그래서 이전의 `i` 값을 저장할 수 있는 `cur` 인자를 받는다.

dfs를 돌리면서 `team[0]` (스타트팀)에 팀원을 모두 고르면 (cnt==N/2) `visited` 배열의 값 false인 인덱스는 모두 `team[1]` (링크팀)의 팀원이라고 볼 수 있다.

그러고 나면 `team[0]`와 `team[1]`을 모두 구했으므로 `calculator` 함수에 넣어 각 팀의 능력치 합산을 비교한다.

`calaulator` 함수에서는 순서고려하고 중복없는 조합을 구해 능력치를 더한다. 같은 조합이지만 2개만 뽑으면 되므로 2중 for문을 돌려서 `acc` 에 누적합산하여 팀 능력치를 구한다.






