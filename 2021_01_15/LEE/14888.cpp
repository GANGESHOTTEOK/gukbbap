#include <iostream>
#include <vector>

using namespace std;

int maxNum = -1000000000;
int minNum = 1000000000;

int calculate(vector <int> &numList, vector <int> &operatorStack) {
    int result = numList[0];
    for (int i = 0; i < operatorStack.size(); i++) {
        if (operatorStack[i] == 0) result += numList[i + 1];
        if (operatorStack[i] == 1) result -= numList[i + 1];
        if (operatorStack[i] == 2) result *= numList[i + 1];
        if (operatorStack[i] == 3) result /= numList[i + 1];
    }
    return result;
}

void backTrack(vector <int> &numList, vector <int> &operatorList,
               vector <bool> &visited, vector <int> &operatorStack) {
    if (operatorStack.size() == operatorList.size()) {
        int result = calculate(numList, operatorStack);
        maxNum = result > maxNum ? result : maxNum;
        minNum = result < minNum ? result : minNum;
    }
    for (int i = 0; i < operatorList.size(); i++) {
        if (!visited[i]) {
            visited[i] = true;
            operatorStack.push_back(operatorList[i]);
            backTrack(numList, operatorList, visited, operatorStack);
            visited[i] = false;
            operatorStack.pop_back();
        }
    }
    
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    vector <int> numList(num, 0);
    vector <int> operatorList;
    vector <bool> visited(num - 1, false);
    vector <int> operatorStack;
    for(int i = 0; i < num; i++) cin >> numList[i];
    for(int i = 0; i < 4; i++) {
        int t; cin >> t;
        for(int j = 0; j < t; j++) operatorList.push_back(i);
    }
    backTrack(numList, operatorList, visited, operatorStack);
    cout << maxNum << endl << minNum << endl;
    return 0;
}


