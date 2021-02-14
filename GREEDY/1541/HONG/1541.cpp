#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    int tmp=0, cnt=0;
    int num[51]={0,}, op=1;
    string exp;

    cin >> exp;

    exp+='-';

    for(int i=0;i<exp.length();i++){
        if(exp[i]=='+') {
            num[cnt++] = op*tmp;
            op = 1;
        }
        else if(exp[i]=='-') {
            num[cnt++] = op*tmp;
            op = -1;
        }
        else {
            tmp = tmp*10 + exp[i] - '0';
            continue;
        }
        tmp = 0;
    }

    int idx=0,sum=0,total=0;
    num[cnt] = -1;

    while(num[idx]>=0) total+=num[idx++];

    for(int i=idx;i<cnt;i++){
        sum+=abs(num[i]);
        if(num[i+1]>0) continue;
        total-=sum;
        sum=0;
    }
    
    cout << total;
    return 0;
}