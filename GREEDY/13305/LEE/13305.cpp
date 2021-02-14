#include <iostream>
#include <vector>
#define MAX_VAL 1000000001
using namespace std;

int n, t;
long long int total = 0, min_price = MAX_VAL;
vector <long int> road;

int main(void) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        road.push_back(t);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        min_price = t < min_price ? t : min_price;
        total += min_price * road[i];
    }
    cin >> t;
    cout << total << endl;
    return 0;
}
