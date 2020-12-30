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
