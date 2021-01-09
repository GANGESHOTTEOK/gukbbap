#include <iostream>
#define MAX_SIZE 2002

using namespace std;

int main(void) {
    int list[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) list[i] = 0;
    int size = 0;
    cin >> size;
    for (int i = 0; i < size; i++) {
        int input = 0;
        cin >> input;
        list[input + 1001] = 1;
    }
    for (int i = 0; i < MAX_SIZE; i++) {
        if (list[i]) cout << i - 1001 << endl;
    }
    return 0;
}
