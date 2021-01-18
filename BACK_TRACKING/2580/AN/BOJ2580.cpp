#include <bits/stdc++.h>
using namespace std;
int sudoku[9][9];
vector< unordered_set<int> > R(9), C(9), S(9);
vector< pair<int,int> > blank;
int N;
int isFit(int row, int col, int val) {
    if(C[col].find(val)!=C[col].end()) return 0;
    if(S[row/3*3+col/3].find(val)!=S[row/3*3+col/3].end()) return 0;
    return 1;
}
void dfs(int depth) {
    if(depth==N) {
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) 
                cout << sudoku[i][j] << " ";
            cout << "\n";
        }
        exit(0);
    }
    int r = blank[depth].first;
    int c = blank[depth].second;
    for(int i=1; i<=9; i++) {
        if(R[r].find(i) != R[r].end()) continue;
        if(!isFit(r,c,i)) continue;
        sudoku[r][c] = i;
        R[r].insert(i);
        C[c].insert(i);
        S[r/3*3+c/3].insert(i);
        dfs(depth+1);
        R[r].erase(i);
        C[c].erase(i);
        S[r/3*3+c/3].erase(i);
    }
}
int main() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            int temp;
            cin >> temp;
            sudoku[i][j] = temp;
            if(!temp) blank.push_back(make_pair(i,j));
            else {
                R[i].insert(temp);
                C[j].insert(temp);
                S[i/3*3+j/3].insert(temp);
            }
        }
    }
    N = blank.size();
    dfs(0);
}