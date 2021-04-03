#include <bits/stdc++.h>
using namespace std;
int main() {
    cin.tie(NULL);ios::sync_with_stdio(false);cout.tie(NULL);
    int N;
    cin >> N;
    vector<int> A(N), LIS;
    for(int i=0; i<N; i++) cin >> A[i];
    LIS.push_back(A[0]);
    for(int i=0; i<N; i++) {
        if(LIS.back() < A[i]) LIS.push_back(A[i]);
        else if(LIS.back() == A[i]) continue;
        else {  // find lower_bound
            int left=0, right=LIS.size(), lower=0;
            while(left<=right) {
                int mid = (left+right)/2;
                if(LIS[mid]<A[i]) left = mid+1;
                else {
                    right = mid-1;
                    lower = mid;
                }
            }
            LIS[lower] = A[i];
        }
    }
    cout << LIS.size();
}