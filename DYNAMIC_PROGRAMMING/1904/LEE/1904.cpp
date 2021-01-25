#include <iostream>

using namespace std;

int num_list[1000001] = {0, };

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    num_list[1] = 1;
    num_list[2] = 2;
    for (int i = 3; i <= n; i++) {
        num_list[i] = (num_list[i - 1] + num_list[i - 2]) % 15746;
        
    }
    cout << num_list[n] << endl;
    return 0;
}

