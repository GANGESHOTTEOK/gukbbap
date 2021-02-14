#include <iostream>
#include <vector>
using namespace std;

int n, t;
long long int total = 0, gas = 0;
vector <int> city;
vector <long int> road;

int main(void) {
    cin >> n;
    for (int i = 0; i < n - 1; i++) {
        cin >> t;
        road.push_back(t);
    }
    for (int i = 0; i < n; i++) {
        cin >> t;
        city.push_back(t);
    }
    int min_price = city[0];
    total = city[0] * road[0];
    for (int i = 1; i < n - 1; i++) {
        if (min_price > city[i]) {
            min_price = city[i];
        }
        total += min_price * road[i];
    }
    cout << total << endl;
    return 0;
}
