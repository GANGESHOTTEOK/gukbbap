#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct conf {
    long long start;
    long long end;
};

bool compare(conf std, conf cmp) {
    if (std.end == cmp.end) return std.start < cmp.start;
    return std.end < cmp.end;
}
vector <conf> confList;
int n;

int main(void) {
    cin >> n;
    confList = vector <conf>(n);
    for (int i = 0; i < n; i++) cin >> confList[i].start >> confList[i].end;
    sort(confList.begin(), confList.end(), compare);
    
    long long int end = confList[0].end;
    int count = 1;
    for (int i = 1; i < n; i++) {
        if (confList[i].start >= end) {
            end = confList[i].end;
            count++;
        }
    }
    cout << count;
    
    return 0;
}
