BOJ 9461번 파도반 수열

문제 접근
---
![파도반수열](https://www.acmicpc.net/upload/images/pandovan.png)

다음과 같이 나선형으로 커지는 삼각형의 변의 길이들을 파도반 수열이란다.

한번 수열을 살펴보면 1,1,1,2,2 이후 3부터 이전의 변과 그 전전전전 변의 길이를 더한 값이다.
즉 `P[n]= P[n-1] + P[n-5]`이라는 점화식을 간단하게 만들 수 있다.

```cpp
int main(){
    int T,tmp;
    long int P[100]={1,1,1,2,2};
    cin >> T;

    for(int i=5;i<100;i++)
        P[i] = P[i-1] + P[i-5];
    
    for(int i=0;i<T;i++){
        cin >> tmp;
        cout << P[tmp-1] << "\n";
    }

    return 0;
}
```
문제 풀이
---

메모리제이션을 위한 `P[100]` 에 초기값 {1,1,1,2,2} 을 넣어주고, 입력받은 값을 출력.

결과
---
![result](https://i.ibb.co/frvwt5b/image.png)