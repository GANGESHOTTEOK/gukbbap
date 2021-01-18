#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

bool checkQueen(vector <int> &queen) {
    int comp = (int) queen.size() - 1;
    for (int i = 0; i < queen.size() - 1; i++) {
        if (abs(queen[i] - queen[comp]) == abs(i - comp)) return false;
    }
    return true;
}

int countCase(vector <bool> &visited, vector <int> &queen) {
    int ret = 0; int n = (int) visited.size();
    if (queen.size() == n) {
        return 1;
    }
    for (int i = 0; i < n; i++){
        if (!visited[i]) {
            visited[i] = true;
            queen.push_back(i);
            if (checkQueen(queen)) {
                ret += countCase(visited, queen);
            }
            visited[i] = false;
            queen.pop_back();
        }
    }
    return ret;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n; cin >> n;
    vector <bool> visited(n, false);
    vector <int> queen;
    cout << countCase(visited, queen) << endl;
    return 0;
}


