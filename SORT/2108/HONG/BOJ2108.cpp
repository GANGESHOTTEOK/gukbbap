    #include <iostream>
    #include <vector>
    #include <cmath>
    #include <algorithm>
    using namespace std;

    int N;
    vector<int> nums;

    void get_average(){
        double sum = 0;

        for(int i=0;i<N;i++)
            sum+=nums[i];
        
        cout <<  round(sum / (double)N) << "\n";
    }

    void get_median(){
        sort(nums.begin(),nums.end());
        cout << nums[(N-1)/2] << "\n";
    }

    void get_mode(){
        vector<int> mode_rank;
        int max[2] = {0,};
        int mode[8001] = {0,};

        for(int i=0;i<N;i++)
            mode[nums[i]+4000]++;
        
        for(int i=0;i<=8000;i++){
            if(max[0] < mode[i]){
                max[0] = mode[i];
                max[1] = i;
                mode_rank.clear();
                mode_rank.push_back(i);
            }
            else if(max[0] == mode[i]){
                mode_rank.push_back(i);
            }
        }
        
        mode_rank.push_back(8001);

        if(mode_rank[1] != 8001)
            cout << mode_rank[1]-4000 << "\n";
        else
            cout << mode_rank[0]-4000 << "\n";
    }

    void get_scope(){
        cout << nums[N-1]-nums[0];
    }

    int main(){
        int tmp;

        cin >> N;

        for(int i=0;i<N;i++){
            cin >> tmp;
            nums.push_back(tmp);
        }

        get_average();
        get_median();
        get_mode();
        get_scope();

        return 0;
    }