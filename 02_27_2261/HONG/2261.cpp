#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Coordinate{ int x, y; };

int n = 1, minDistance = 10000 * 10000 * 4;
vector <Coordinate> coord;
bool compare(Coordinate c1, Coordinate c2) { return c1.x < c2.x; }

int distance(Coordinate & c1, Coordinate & c2) {
    return (c1.x - c2.x) * (c1.x - c2.x) + (c1.y - c2.y) * (c1.y - c2.y);
}

int getMinDistance(int left, int right) {
    if (right - left + 1 == 2)  {
        return distance(coord[left], coord[right]);
    }
    else if (right - left + 1 == 3) {
        int rValue = min(distance(coord[left], coord[left + 1]),
                         distance(coord[left], coord[right]));
        rValue = min(rValue, distance(coord[left + 1], coord[right]));
        return rValue;
    }
    int mid = (left + right) / 2;
    int rValue = getMinDistance(left, mid);
    rValue = min(rValue, getMinDistance(mid + 1, right));
    while(left != right) {
        if (left < right) {
            rValue = min(rValue, distance(coord[left], coord[right]));
            left++;
        }
        if (right > left) {
            rValue = min(rValue, distan ce(coord[left], coord[right]));
            right--;
        }
    }
    return rValue;
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    coord = vector<Coordinate>(n);
    for (int i = 0; i < n; i++) cin >> coord[i].x >> coord[i].y;
    sort(coord.begin(), coord.end(), compare);
    cout << getMinDistance(0, n - 1) << endl;
    return 0;
}
