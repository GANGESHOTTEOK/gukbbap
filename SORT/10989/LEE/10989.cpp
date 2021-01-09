#include <iostream>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    int list[10000] = {0, };
    for (int i = 0; i < num; i++) {
        int temp; cin >> temp;
        list[temp - 1] += 1;
    }
    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < list[i]; j++) {
            cout << i + 1 << '\n';
        }
    }
    return 0;
}
