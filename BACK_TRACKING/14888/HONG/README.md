
# 백준 14888번 문제

---

### 문제 해결 날짜 및 시간

- 2021년 01월 15일 20시 01분

---
### 메모리 및 시간

- 메모리 : 2016KB
- 시간 : 288ms

---

### 접근 방식
```cpp
#include <iostream>
using namespace std;
#define MAXVALUE 1000000000

int N;
int maxval = -MAXVALUE, minval = MAXVALUE;
int AN[11],OPC[10],temp[11],OP[4] = {0,};
bool visited[11] = {false,};

int calculator(int *arr){
    //temp배열의 조합을 AN과 계산해본다.

    int acc = AN[0];
    // 좌항부터 계산하여 누적된 계산값을 저장

    for(int i=0;i<N-1;i++){
        // + - * / 을 각각 1 2 3 4로 저장하였으므로 그에 맞게 저장
        if(arr[i]==1) acc += AN[i+1];
        if(arr[i]==2) acc -= AN[i+1];
        if(arr[i]==3) acc *= AN[i+1];
        if(arr[i]==4) acc /= AN[i+1];
    }

    return acc;
    // 누적값(==계산값)을 리턴
}

void cbn(int idx){
    // OPC의 수많은 조합의 경우의 수를 찾는다. idx는 재귀호출시 깊이의 단계를 알려줌 (temp배열의 원소의 갯수)

    if (idx == N-1){
        // N-1에 도달하면 temp 배열에 연산자가 모두 들어갔으므로 계산값을 구해야한다.

        int value  = calculator(temp);
        // 계산값

        maxval = maxval > value ? maxval : value;
        minval = value > minval ? minval : value;
        // 계산된 값 value를 가지고 max, min와 비교

        return;
    }

    for (int i = 0; i < N-1; i++){
        if (!visited[i]){
            // 만약 방문한 적이 없다면

            temp[idx] = OPC[i];
            visited[i] = true;
            cbn(idx + 1);
            // 방문한적 없는 원소를 temp 에 추가하고 원소방문표시 후 다음 원소로 재귀 

            visited[i] = false;
            // 하위 단계를 모두 훑고 오면 되돌아 왔으므로 원소 방문표시를 지움
        }
    }
}

int main(){   
    cin >> N;

    for(int i=0;i<N;i++)
        cin >> AN[i];
        // N개의 숫자를 배열 AN에 저장
    
    cin >> OP[0] >> OP[1] >> OP[2] >> OP[3];
    // 연산자 + - * / 의 갯수를 배열 OP에 저장

    int idx = 0;

    for(int i=1;i<=4;i++)
        for(int j=0;j<OP[i-1];j++) 
            OPC[idx++] = i;
    //배열 OP를 나열하여 OPC에 + - * = 를 각각 1 2 3 4로 지정하여 N-1개 저장

    cbn(0);
    
    cout << maxval << "\n" << minval;
    //min 과 max를 구하여 출력

    return 0;  
}
```

- 입력해주는 N개의 숫자를 저장하는 배열 `AN`
- 각 4종류의 연산자 (+-*/)의 갯수를 입력받는 배열 `OP`
- `OP`배열을 +-*/를 1,2,3,4로 구분하여 나열한 배열 `OPC`
- `OPC` 배열을 조합하여 나올수 있는 경우의 수를 임시 저장하는 배열 `temp`
- `cbn` 함수의 재귀적 호출을 하며 dfs 탐색을 할때 방문 여부를 저장하는 배열 `visited`
- 조합의 여러경우의 수 중 하나인 `temp`를 계산하여 `maxval과` `minval과` 비교하여 계산값의 최대 최소를 구함





