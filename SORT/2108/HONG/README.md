
# 백준 2108번 문제

---
### 문제 해결 날짜 및 시간

- 2020년 1월 6일
- 메모리 : 5100KB
- 시간 : 206ms

---

### 접근 방식

```c++
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
```

주어진 문제에서는 총 4가지 값을 구해야 한다. 
1. `산술평균` : N개의 수들의 합을 N으로 나눈 값  
2. `중앙값` : N개의 수들을 증가하는 순서로 나열했을 경우 그 중앙에 위치하는 값  
3. `최빈값` : N개의 수들 중 가장 많이 나타나는 값  
4. `범위` : N개의 수들 중 최댓값과 최솟값의 차이    

나는 각각 `get_average` `get_median` `get_mode` `get_scope`함수로 쪼개어서 값을 각각 구하고자 했다.

#### 산술평균

```c++
void get_average(){
    double sum = 0;

    for(int i=0;i<N;i++)
        sum+=nums[i];
    
    cout <<  round(sum / (double)N) << "\n";
}
```
int `N`과 vector `nums`는 전역으로 설정하여 main 함수 밖에서도 쓸 수 있다.

`sum`을 선언하여 `nums`에 저장된 수들을 모두 더해서 N만큼 나누어준다.

**다만** 산술평균값이 소수점 첫째 자리에서 반올림 되므로 `double`로 선언해준다. 처음에는 `sum`을 `float` 로 선언하였는데 범위가 오버되었는지 통과하지 못했다.

#### 중앙값

```c++
void get_median(){
    sort(nums.begin(),nums.end());
    cout << nums[(N-1)/2] << "\n";
}
```
`nums`의 값들을 증가하는 방향으로 정렬하였을 때 중앙에 위치하는 값을 찾아야 하므로, 일단 `sort` 함수로 `nums` 벡터를 정렬 후 중앙 *(N-1)/2* 에 위치한 값을 출력.

#### 최빈값

```c++
void get_mode(){
    int max[2] = {0,};
    int mode[8001] = {0,};
    vector<int> mode_rank;

    for(int i=0;i<N;i++)
        mode[nums[i]+4000]++;
    
    for(int i=0;i<=8000;i++){

        if(max[0] < mode[i]){
            max[0] = mode[i];
            max[1] = i;
            mode_rank.clear();
            mode_rank.push_back(i);
        }

        else if(max[0] == mode[i])
            mode_rank.push_back(i);
        
    }

    mode_rank.push_back(8001);

    if(mode_rank[1] != 8001)
        cout << mode_rank[1]-4000 << "\n";
    else
        cout << mode_rank[0]-4000 << "\n";
}
```
최빈값을 구하기 위해 `counting sort`를 이용한다. 

선언된 값들의 절댓값은 4000이 넘지 않으므로 8001크기의 `mode` 배열을 선언한다. 0부터 N까지 모든 값을 돌며 각각의 값이 인덱스가 되어 값을 더해준다.

최빈값을 구하기 위하여 가장 많이 나온 최빈값과 인덱스를 저장할 수 있는 `max[2]` 배열을 선언하고, 8001의 값들을 돌며 가장 많이 나온 수를 찾아 저장한다.

다만, 문제에서는 최빈값이 같은 수가 여러개 나올경우 그들 중 2번째로 작은 값을 출력하라고 하기 때문에, 최빈값이 같은 수들을 저장할 수 있는 배열이 필요하다. 그래서 `mode_rank` 를 사용하였다. 

for문을 순회하며 현 최대 최빈값 (`max[0]`)과 같은 수를 찾는다면 mode_rank에 추가된다. 새로운 최대 최빈값을 발견한다면 mode_rank는 초기화되고 `mode_rank[0]` 에 `max[1]` 값이 추가된다. mode_rank 에는 최빈값을 가진 수들의 정렬된 모임이 된다.

최빈값을 가진 수가 1개 일수도 있으므로 고려해주며 출력한다.

#### 범위

```c++
void get_scope(){
    cout << nums[N-1]-nums[0];
}
```

중앙값을 구할 때 이미 `nums` 오름차순으로 정렬해두었으므로 마지막값에 첫번째 값을 뺴어 출력
