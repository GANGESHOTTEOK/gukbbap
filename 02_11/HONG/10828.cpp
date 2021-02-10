#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    int N,num=0;
    stack<int> s;
    string tmp;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp;
        if(tmp=="push") {
            cin >> num;
            s.push(num);
        }
        else if(tmp=="pop") {
            if(s.empty()) cout << -1 << endl;
            else{
                cout << s.top() << endl;
                s.pop();
            }
        }
        else if(tmp=="size") cout << s.size() << endl;
        else if(tmp=="empty") {
            if(s.empty()) cout << 1 <<endl;
            else cout << 0 << endl;
        } 
        else if(tmp=="top") {
            if(s.empty()) cout << -1 << endl;
            else cout << s.top() << endl;
        }
    }
    return 0;
}