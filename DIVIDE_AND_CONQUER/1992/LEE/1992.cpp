#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;
string t;
string * video;
string compressResult = "";

void init() {
    video = new string[n];
    for (int i = 0; i < n; i++) cin >> video[i];
}

bool checkSameData(int len, int x, int y) {
    char check = video[x][y];
    for (int i = x; i < x + len; i++) {
        for (int j = y; j < y + len; j++) {
            if (check != video[i][j]) return false;
        }
    }
    return true;
}

void compressVideo(int len, int x, int y) {
    if (checkSameData(len, x, y)) {
        compressResult += video[x][y];
        return;
    }
    compressResult += "(";
    for (int i = x; i < x + len; i += len / 2) {
        for (int j = y; j < y + len; j += len / 2) {
            if (checkSameData(len / 2, i, j)) compressResult += video[i][j];
            else {
                compressVideo(len / 2, i, j);
            }
        }
    }
    compressResult += ")";
}

int main(void) {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    init();
    compressVideo(n, 0, 0);
    cout << compressResult;
    return 0;
}


