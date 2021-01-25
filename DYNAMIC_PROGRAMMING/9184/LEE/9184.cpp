#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int a = 0, b = 0, c = 0;
int w[21][21][21];
void print(int num) {
    printf("w(%d, %d, %d) = %d\n", a, b, c, num);
}
int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    
    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                if (i == 0 || j == 0 || k == 0) w[i][j][k] = 1;
                else {
                    if (i < j && j < k) {
                        w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k];
                    }
                    else {
                        w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1];
                    }
                }
            }
        }
    }
    cin >> a >> b >> c;
    while(a != -1 || b != -1 || c != -1) {
        if (a <= 0 || b <= 0 || c <= 0) {
            print(1);
        }
        else if (a > 20 || b > 20 || c > 20) {
            print(w[20][20][20]);
        }
        else {
            print(w[a][b][c]);
        }
        cin >> a >> b >> c;
    }
    return 0;
}

