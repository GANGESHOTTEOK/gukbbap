#include <iostream>

int main(){
    int N, tmp, fibo[42] = {1,0};;
    
    std::cin >> N;

    for(int i=0;i<=40;i++) 
        fibo[i+2] = fibo[i+1] + fibo[i];
        

    for(int i=0;i<N;i++){
        std::cin >> tmp;
        std::cout << fibo[tmp] << " " << fibo[tmp+1] << "\n";
    }

    return 0;
}