#include <iostream>
#include <vector>
using namespace std;

vector <pair<int, int>> countList(41, make_pair(0, 0));

void print(int n) {
    cout << countList[n].first << " " << countList[n].second << "\n";
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    countList[0].first = 1; countList[0].second = 0;
    countList[1].first = 0; countList[1].second = 1;
    for (int i = 2; i < 41; i++) {
        countList[i].first = countList[i - 2].first + countList[i - 1].first;
        countList[i].second = countList[i - 2].second + countList[i - 1].second;
    }
    vector <int> list(n);
    for (int i = 0; i < n; i++) cin >> list[i];
    for (int a: list) print(a);
    return 0;
}


