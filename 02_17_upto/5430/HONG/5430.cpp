#include <iostream>
#include <deque>
#include <vector>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    string p, tmp;
    deque<int> d;
    int T, n;
    cin >> T;
    for(int i=0;i<T;i++){
        cin >> p >> n >> tmp;
        for(int j=1;j<tmp.size()-1;j++) 
            if(tmp[j]!=','){
                d.push_back(tmp[j]-'0');
            }
        
        bool flag = true;
        for(int j=0;j<p.size();j++){
            if(p[j]=='R') 
                flag *= -1;
            else{
                if(d.empty()) {
                    cout << "error" << "\n";
                    break;
                }
                if(flag) d.pop_front();
                else d.pop_back();
            }
        }
        if(!d.empty()){
            if(flag)
                for(int j=0;j<p.size();j++)
                    cout << d[j] << " ";
            else 
                for(int j=p.size()-1;j>=0;j++)
                    cout << d[j] << " ";
            cout << endl;
        }
    }
    return 0;
}
