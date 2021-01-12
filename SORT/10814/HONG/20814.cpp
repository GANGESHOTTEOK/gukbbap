#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int N;

    cin >> N;

    typedef struct{
        int age;
        int sqc;
        string name;
    }Member;
    vector<Member> memvec(N);

    for(int i=0;i<N;i++){
        cin >> memvec[i].age >> memvec[i].name;
        memvec[i].sqc = i;
    }
    
    sort(memvec.begin(),memvec.end(),[](Member &a, Member &b){
        return a.age == b.age ? a.sqc < b.sqc : a.age < b.age;});

    for(auto v:memvec)
        cout << v.age << " " << v.name << '\n';

    return 0;
}