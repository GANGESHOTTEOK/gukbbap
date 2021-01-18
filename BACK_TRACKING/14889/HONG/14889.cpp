    #include <iostream>
    #include <cmath>
    using namespace std;

    int N, min_diff = 2147483647;
    bool visited[20] = {false,};
    int S[20][20], team[2][10];

    int calculator(int *team){
        int acc = 0;

        for(int i=0;i<N/2;i++)
            for(int j=0;j<N/2;j++){
                if(i==j) continue;
                acc += S[team[i]][team[j]];
            }

        return acc;
    }

    void cbn(int cnt,int cur){
        if (cnt == N/2){
            for(int i=0,j=0; i<N; i++)
                if (!visited[i]) team[1][j++] = i;

            int cur_diff = abs( calculator(team[0]) - calculator(team[1]) );
            min_diff = cur_diff > min_diff ? min_diff : cur_diff;
            
            return;
        }
        for (int i = cur+1; i < N; i++){

            if (visited[i]) continue;
            visited[i] = true;
            team[0][cnt] = i;
            cbn(cnt + 1,i); 
            visited[i] = false;
        }
    }

    int main(){
        cin >> N;

        for(int i=0;i<N;i++) 
            for(int j=0;j<N;j++) 
                cin >> S[i][j];

        cbn(0,0);

        cout << min_diff;

        return 0;
    }