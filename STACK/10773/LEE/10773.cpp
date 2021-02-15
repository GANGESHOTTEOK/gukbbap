#include <iostream>
#include <vector>

using namespace std;

vector <long long int> num;
int n, t;
int long long sum = 0;
int main(void) {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> t;
        if (t) num.push_back(t);
        else num.pop_back();
    }
    for (auto n: num) sum += n;
    cout << sum << endl;
    return 0;
}
