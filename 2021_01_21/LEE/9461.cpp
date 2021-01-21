#include <iostream>

using namespace std;

long int num_list[101] = {0, 1, 1, 1, 2, 2, 0, };

long int getAns(int n) {
    for (int i = 6; i <= n; i++) {
        num_list[i] = num_list[i - 5] + num_list[i - 1];
    }
    return num_list[n];
}
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int temp; cin >> temp;
        cout << getAns(temp) << endl;
    }
    return 0;
}

