    #include <iostream>
    #include <algorithm>
    using namespace std;

    int main(){
        int score[300][2];
        int N;

        cin >> N;

        for(int i=0;i<N;i++)
            cin >> score[i][0];

        score[0][1] = score[0][0];
        score[1][1] = score[1][0] + score[0][0];
        score[2][1] = score[2][0] + max(score[1][0], score[0][0]);
        
        for(int i=3;i<N;i++)
            score[i][1] = score[i][0] + max(score[i-2][1], score[i-1][0] + score[i-3][1]);
     
        cout << score[N-1][1];
    
        return 0; 
    }