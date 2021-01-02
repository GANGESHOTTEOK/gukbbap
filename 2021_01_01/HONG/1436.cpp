#include <iostream>
#include <string>
using namespace std;

int main(){
    string N[10000] = {"",};
    N[10000] = "-1";

    string end("666");
    int count = 
    for(int i=0;i<10;i++){
        if(i==6) continue;

        for(int j=0;j<10;j++){
            if(j==6) continue;

            for(int k=0;k<10;k++){
                if(k==6) continue;
                

            }
        }
    }
    string end2 = end.insert(2,"5");
    end.erase(2,1);

    cout << end << end2 ;

    return 0;
}