#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int N;
vector<int> nums;

void get_average(){
    float sum = 0;

    for(int i=0;i<N;i++)
        sum+=nums[i];
    
    cout <<  round(sum / (float)N);
}

void get_median(){
    sort(nums.begin(),nums.end());
    cout << nums[(N-1)/2];
}

void get_mode(){
    int max, sum = 0;
    int mode[8001];

    for(int i=0;i<N;i++)
        mode[nums[i]+4000]++;
    
    for(int i=0;i<=8000;i++)
        max = max > mode[i] ? max : mode[i];

    cout << max;
}

int main(){
    int tmp;

    cin >> N;

    for(int i=0;i<N;i++){
        cin >> tmp;
        nums.push_back(tmp);
    }

    // get_average();
    // get_median();
    get_mode();
    // get_scope();

    return 0;
}