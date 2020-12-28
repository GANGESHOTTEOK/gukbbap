
# 백준 2798번 문제

---

### 문제 해결 날짜 및 시간

- 2020년 12월 28일 16시 54분

---

### 접근 방식
재귀방식으로 풀어보려고 하였으나 주어진 조건에서는 3중 반복문에 비해 큰 이점을 찾기 힘들어 반복문으로 해결.
```c++
#include <iostream>
using namespace std;

int main(void) {
    int cardNum = 0; int blackJack = 0;
    cin >> cardNum >> blackJack;
    int cardList[cardNum];
    for (int i = 0; i < cardNum; i++) cin >> cardList[i];
    
    long int cardSum = -1;
    
    for (int i = 0; i < cardNum; i++) {
        long int tempCardSum = cardList[i];
        for (int j = i + 1; j < cardNum; j++) {
            tempCardSum+= cardList[j];
            for (int k = j + 1; k < cardNum; k++) {
                tempCardSum += cardList[k];
                if (tempCardSum == blackJack) {
                    cardSum = tempCardSum;
                    break;
                }
                else if (tempCardSum < blackJack && tempCardSum > cardSum) cardSum = tempCardSum;
                tempCardSum -= cardList[k];
            }
            tempCardSum -= cardList[j];
        }
    }
    cout << cardSum;
    return 0;
}
```
다른 코드는 모두 평범하나 카드의 합이 `blackJack`(`m`과 동일)와 같은 경우 바로 반복문을 탈출하게 했다.




