#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;
    string tmp;
    vector<string> strvec;
    
    cin >> N;

    for(int i=0;i<N;i++){
        cin >> tmp;
        strvec.push_back(tmp);
    }   
    
    sort(strvec.begin(),strvec.end(),[](string &a,string &b){
        return a.length() == b.length() ? a < b : a.length() < b.length();});

    strvec.push_back("-1");

    for(int i=0;i<N;i++){
        if(strvec[i]==strvec[i+1]) continue;
        cout << strvec[i] << '\n';
    }

    return 0;
}