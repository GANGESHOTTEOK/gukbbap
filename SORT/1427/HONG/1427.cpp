#include <iostream>
#include <cstring>
#include <algorithm>
#include <functional>
using namespace std;

int main(){
    char chr[10];

    cin >> chr;

    sort(chr, chr+strlen(chr),greater<int>());

    cout << chr;

    return 0;
}