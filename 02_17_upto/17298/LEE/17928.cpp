#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int n;
vector <int> arr;
vector <int> ans;
stack <int> s;

void init() {
    cin >> n;
    arr = vector <int>(n);
    ans = vector <int>(n, -1);
    for (int i = 0; i < n; i++) cin >> arr[i];
}

void NGE() {
    for (int i = 0; i < n; i++) {
        while(!s.empty() && arr[s.top()] < arr[i]) {
            ans[s.top()] = arr[i];
            s.pop();
        }
        s.push(i);
    }
    for (int i = 0; i < n; i++) cout << ans[i] << " ";
}

int main(void) {
    init();
    NGE();
    return 0;
}



