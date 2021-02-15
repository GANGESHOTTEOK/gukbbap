#include <iostream>
#include <string>
#include <stack>
using namespace std;

const string balanced_world(const string& str){
    stack<char> bracket;

    for(int i=0;i<str.length();i++){
        if(str[i]=='(' || str[i]=='[') bracket.push(str[i]);

        else if(str[i]==')' || str[i]==']'){

            if(bracket.empty()) return "no";

            if(bracket.top() == str[i]-1 || bracket.top() == str[i]-2) bracket.pop();

            else return "no";
        }
    }
    if(bracket.empty()) return "yes";
    else return "no";
}

int main(){
    string str;
    
    while(true){
        getline(cin,str);
        if(str==".") break;
        cout << balanced_world(str) <<"\n";
    }
    return 0;
}