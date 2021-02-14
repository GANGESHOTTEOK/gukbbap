#include <bits/stdc++.h>
using namespace std;
string s;
vector<char*> a;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    getline(cin,s);
    char *s_buff = new char[50];
    strcpy(s_buff, s.c_str());
    char *ptr = strtok(s_buff,"-");
    while(ptr != NULL) {
        a.push_back(ptr);
        ptr = strtok(NULL, "-");
    }
    for(int i=0; i<a.size(); i++) {
        int subsum = 0;
        ptr = strtok(a[i],"+");
        while(ptr != NULL) {
            subsum += stoi(ptr);
            ptr = strtok(NULL, "+");
        }
        v.push_back(subsum);
    }
    cout << v[0]-accumulate(v.begin()+1,v.end(),0);
}