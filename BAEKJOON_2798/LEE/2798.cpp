#include <iostream>

using namespace std;

int main(void) {
    int cardNum = 0; int blackJack = 0;
    cin >> cardNum >> blackJack;
    int cardList[cardNum];
    for (int i = 0; i < cardNum; i++) cin >> cardList[i];
    
    long int cardSum = -1;
    
    for (int i = 0; i < cardNum; i++) {
        long int tempCardSum = cardList[i];
        for (int j = i + 1; j < cardNum; j++) {
            tempCardSum+= cardList[j];
            for (int k = j + 1; k < cardNum; k++) {
                tempCardSum += cardList[k];
                if (tempCardSum == blackJack) {
                    cardSum = tempCardSum;
                    break;
                }
                else if (tempCardSum < blackJack && tempCardSum > cardSum) cardSum = tempCardSum;
                tempCardSum -= cardList[k];
            }
            tempCardSum -= cardList[j];
        }
    }
    cout << cardSum;
    
    return 0;
}


