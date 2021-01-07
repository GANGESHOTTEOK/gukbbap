#include <iostream>
#include <cmath>
using namespace std;


int main(){
    int N, Nnum, count, sum, min= 0;
    int num[7];

    cin >> N;

    for(int i=1; i<64; i++){
        sum, count = 0;
        Nnum = N-i;
        
        fill_n(num, 7, -1);

        while (Nnum >= 1){
            num[count] = Nnum%10;
            Nnum /= 10;
            count++;
        }

        for(int j=0; num[j] != -1; j++)
            sum += num[j]*(pow(10, j) + 1);
        
        if(sum == N) min = N-i;
    }

    cout << min;

    return 0;
}