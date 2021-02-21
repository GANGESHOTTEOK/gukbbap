#include <iostream>
#include <string>
#include <queue>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    queue<int> q;
    string tmp;
    int num, N;
    cin >> N;
    for(int i=0;i<N;i++) {
        cin >> tmp;
        if(tmp=="push"){
            cin >> num;
            q.push(num);
        }
        else if(tmp=="pop"){
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(tmp=="size") cout << q.size() << "\n";
        else if(tmp=="empty") cout << q.empty() << "\n";
        else if(tmp=="front") {
            if(q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(tmp=="back"){
            if(q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
    return 0;
}