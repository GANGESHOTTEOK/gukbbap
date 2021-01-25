#include <iostream>
#include <cmath>
using namespace std;

int cost[1000][3];
int minCost[1000][3];

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }
    minCost[0][0] = cost[0][0]; minCost[0][1] = cost[0][1]; minCost[0][2] = cost[0][2];
    for (int i = 1; i < n; i++) {
        minCost[i][0] += min(minCost[i - 1][1], minCost[i - 1][2]) + cost[i][0];
        minCost[i][1] += min(minCost[i - 1][0], minCost[i - 1][2]) + cost[i][1];
        minCost[i][2] += min(minCost[i - 1][0], minCost[i - 1][1]) + cost[i][2];
    }
    int result = min(minCost[n - 1][0], minCost[n - 1][1]);
    result = min(result, minCost[n - 1][2]);
    cout << result << endl;
    return 0;
}


