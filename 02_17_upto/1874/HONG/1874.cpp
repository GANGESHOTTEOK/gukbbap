#include <vector>
#include <stack>
#include <iostream>
using namespace std;

int main(){
    bool push_pop[200000] ={false,};
    int n, s[100000]={0,};
    stack<int> stk;
    stk.push(0);

    cin >> n;
    for(int i=0;i<n;i++) cin >> s[i];

    for(int i=1,j=0;i+j<=2*n;){

        if(stk.top() == s[j]) {
            stk.pop();
            j++;
        }
        else {
            push_pop[i+j-1]=true;
            stk.push(i++);
        }

        if(j>n || i>n+1) {
            cout << "NO";
            return 0;
        }
    }
    for(int i=0;i<2*n;i++) 
            if(push_pop[i]) cout << '+' << "\n";
            else cout << '-' << "\n"; 

    return 0;
}