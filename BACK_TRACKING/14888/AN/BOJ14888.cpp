#include <bits/stdc++.h>
using namespace std;
int N;
int chk[4];
vector<int> oper(4);
vector<int> A, v;
vector<long long> result;
long long getResult() {
    int val = A[0];
    for(int i=1; i<N; i++) {
        switch (v[i-1]) {
            case 0:
                val += A[i];
                break;
            case 1:
                val -= A[i];
                break;
            case 2:
                val *= A[i];
                break;
            case 3:
                val /= A[i];
                break;
            default:
                break;
        }
    }
    return val;
}
void dfs(int depth) {
    if(depth==N-1) {
        long long r = getResult();
        result.push_back(r);
        return;
    }
    for(int i=0; i<4; i++) {
        if(chk[i]==oper[i]) continue;
        chk[i]++;
        v.push_back(i);
        dfs(depth+1);
        v.pop_back();
        chk[i]--;
    }
}
int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        int temp;
        cin >> temp;
        A.push_back(temp);
    }
    for(int i=0; i<4; i++) {
        cin >> oper[i];
    }
    dfs(0);
    int M = *max_element(result.begin(), result.end());
    int m = *min_element(result.begin(), result.end());
    cout << M << "\n" << m;
    return 0;
}