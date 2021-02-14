#include <iostream>
using namespace std;

const char* is_VPS(char* s){
    int vps=0;
    for(int i=0;s[i]!='\0';i++){
        if(s[i]=='(') vps++;
        else vps--;
        if(vps<0) return "NO";
    }
    if(vps) return "NO";
    else return "YES";
}

int main(){
    char str[50];
    int T;
    cin >> T;

    for(;T--;) {
        cin >> str;
        cout << is_VPS(str) << "\n";
    } 
    return 0;
}