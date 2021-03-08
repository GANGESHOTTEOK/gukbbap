#include <bits/stdc++.h>
using namespace std;
int N,M;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    vector<int> A(N);
    for(int i=0; i<N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    cin >> M;
    for(int i=0; i<M; i++) {
        int num;
        cin >> num;
        int left=0, right=N-1, flag=0;
        while(left<=right) {
            int mid = (left+right)/2;
            if(A[mid]<num) left = mid+1;
            else if(A[mid]>num) right = mid-1;
            else {
                flag = 1;
                break;
            }
        }
        cout << flag << "\n";
    }
}