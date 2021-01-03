
<<<<<<< HEAD
# 백준 10872번 문제
=======
# 백준 2798번 문제
>>>>>>> main

---

### 문제 해결 날짜 및 시간

- 2020년 12월 28일

---

### 접근 방식
  N개의 카드 중에 3장을 뽑아서 조합을 보아야하기 때문에 3중 반복문을 돌려야한다. 처음보는 문제였다면 이 방법으로 풀지 않았을 것이지만 Brute Force 문제임을 알고 있었기에 3중 for 문을 돌렸다.

 ```c++
 #include <iostream>
using namespace std;

int main(){
    int N , M;
    int C[100];
    cin >> N >> M;

    for(int i=0; i<N; i++) cin >> C[i];

    int max = 0;

    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(M >= C[i]+C[j]+C[k] && max < C[i]+C[j]+C[k])
                    max = C[i]+C[j]+C[k];
            }
        }
    }   

    cout << max;

    return 0;
}
 ``` 

`j`는 `i+1` 부터, `k`는 `j+1`부터 시작하여 중복하여 카운트하는 경우가 없게 하였다.  
`M`을 오버하지 않으면서, 기존의 `max`보다 클 경우 값을 대체한다. 마지막에는 `max`를 출력한다.