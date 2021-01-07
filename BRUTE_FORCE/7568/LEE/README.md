
# 백준 7568번 문제

---

### 문제 해결 날짜 및 시간

- 2020년 12월 30일 18시 54분

---

### 접근 방식
```c++
#include <iostream>
#include <vector>

using namespace std;

class People {
private:
    int _rank;
    int _weight;
    int _height;
public:
    People() {
        _rank = 1;
    }
    void setWeight(int w) { _weight = w; }
    void setHeight(int h) { _height = h; }
    void increaseRank() { _rank += 1; }
    int getWeight() { return _weight; }
    int getHeight() { return _height; }
    int getRank() { return _rank; }
};

bool checkBigger(People standard, People compare) {
    return (compare.getHeight() > standard.getHeight()) &&
           (compare.getWeight() > standard.getWeight());
}

int main(void) {
    int num;
    cin >> num;
    vector < People > list(num);
    
    for (int i = 0; i < num; i++) {
        int w, h; cin >> w >> h;
        list[i].setWeight(w); list[i].setHeight(h);
    }
    for (int i = 0; i < num; i++) {
        for (int j = 0; j < num; j++) {
            if (checkBigger(list[i], list[j])) list[i].increaseRank();
        }
    }
    for (int i = 0; i < num; i++) cout << list[i].getRank() << " ";
    return 0;
}
```
그냥 2차원 배열 사용해서 풀 수도 있었는데 좀 더 깔끔한 코드를 위해 클래스를 사용했다.
클래스 멤버 함수와 덩치 비교를 위한 함수를 만들어서 `main`함수에서의 코드를 깔끔하게 만듦.




