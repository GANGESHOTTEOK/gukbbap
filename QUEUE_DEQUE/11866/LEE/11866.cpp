#include <iostream>
#include <queue>

using namespace std;

int n, k, idx = 1;
queue <int> people;

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n >> k;
    for(int i = 1; i <= n; i++) people.push(i);
    
    cout << "<";
    while(people.size() > 1) {
        if (idx == k) {
            cout << people.front() << ", ";
            people.pop();
            idx = 0;
        }
        else {
            people.push(people.front());
            people.pop();
        }
        idx++;
    }
    cout << people.front() << ">";
    return 0;
}

