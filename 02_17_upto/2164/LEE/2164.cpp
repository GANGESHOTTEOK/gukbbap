#include <iostream>
#include <queue>

using namespace std;

int n;
queue <int> num;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) num.push(i);
    while(num.size() > 1) {
        num.pop();
        num.push(num.front());
        num.pop();
    }
    cout << num.front() << "\n";
}

