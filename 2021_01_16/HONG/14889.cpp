#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
int N, group_num = 0 ;
int** ability_arr; 
vector<int> group_1, group_2;
vector<int> answer_vec;
 
void findGroupVal() {
    int group1_sum = 0 , group2_sum = 0 ;
    for (int i = 0; i < group_1.size(); i++) {
        for (int j = 0; j < group_1.size(); j++) {
            if (i == j) continue;
            group1_sum += ability_arr[group_1[i]][group_1[j]]; 
            group2_sum += ability_arr[group_2[i]][group_2[j]]; 
        }
    }
    answer_vec.push_back(abs(group1_sum- group2_sum));
}
 
void findNextGroup() {
    if (!group_num) {

        for (int i = 0; i < N / 2; i++) {
            group_1.push_back(i);
        } 
    }
    else {

        for (int i = 0; i < N / 2; i++) {
            if (group_1[(N / 2 - 1) - i] == ((N - 1) - i)) {  
                continue;
            }
            else {
                group_1[(N / 2 - 1) - i]++;
                int sub_plus = 1; 
                for (int j = (N / 2 - 1) - i + 1; j < N / 2; j++) {
                    group_1[j] = group_1[(N / 2 - 1) - i]  + sub_plus++;
                }
                break;
            }
        }
    }
 

    group_2.clear();
    int group_1_index = 0; 
    for (int i = 0; i < N; i++) {
        if (group_1_index >= N / 2) group_2.push_back(i);
        else if (group_1[group_1_index] == i) {
            group_1_index++;
            continue;
        }
        else {
            group_2.push_back(i);
        }
    } 
    group_num++; 
}
 
int main() {
    cin >> N;
 
    ability_arr = (int**)malloc(sizeof(int*)*N); 
 
    for (int i = 0; i < N; i++) {
        ability_arr[i] = (int*)malloc(sizeof(int)*N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> ability_arr[i][j];
        } 
    }
 
    double fac_num = 1 ; 
    for (double i = N; i > N/2; i--) { 
        fac_num *= (i / (N-i+1));
    }
 
 
    for (int i = 0; i < fac_num ; i++) {
        findNextGroup();
        findGroupVal();  
    }
 
    sort(answer_vec.begin(), answer_vec.end());
    cout << answer_vec[0];
     
    return 0; 
}
