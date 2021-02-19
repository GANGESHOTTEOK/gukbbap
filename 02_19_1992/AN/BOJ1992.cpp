#include <bits/stdc++.h>
using namespace std;
int N;
string img[64];
int idx[4][2] = {{0,0}, {0,1}, {1,0}, {1,1}};
struct Quad{
    int value, row, col;
    vector<Quad*> child;
    Quad(int v, int r, int c) : value(v), row(r), col(c) {}
};
int isQuad(int row, int col, int n) {
    int color = img[row][col];
    for(int i=0; i<n; i++) 
        for(int j=0; j<n; j++) 
            if(img[row+i][col+j] != color) return -1;
    return color;
}
void I2Q(Quad*& quad, int n) {
    if(n==N) {
        int result = isQuad(0,0,n);
        if(result != -1) {
            quad->value = result;
        }
    }
    for(int i=0; i<4; i++) {
        int r = quad->row + n/2*idx[i][0];
        int c = quad->col + n/2*idx[i][1];
        int result = isQuad(r,c,n/2);
        Quad* childQ = new Quad(result,r,c);
        quad->child.push_back(childQ);
        if(result == -1) I2Q(quad->child[i],n/2);
    }
}
void printQTS(Quad* quad) {
    if(quad->value==-1) {
        cout << "(";
        for(auto k:quad->child) printQTS(k);
        cout << ")";
    }
    else cout << quad->value-48;
}
int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    cin >> N;
    for(int i=0; i<N; i++) cin >> img[i];
    Quad* root = new Quad(-1,0,0);
    I2Q(root,N);
    printQTS(root);
}