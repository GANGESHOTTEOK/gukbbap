#include<iostream>
#include<queue>

using namespace std;

int n; // 연산의 개수를 받아줄 변수
priority_queue<int> pq; // int형 우선순위 큐 선언
int main() {
    cin >> n;
    while (n--) { // 연산의 개수만큼 반복
        int x; // 연산에 대한 정보를 받아줄 변수
        cin >> x;
        if (x == 0) { //x가 0이라면
            if (pq.empty()) cout << "0\n";
                // queue가 비어있을 경우 0 출력
            else {
                cout << pq.top() << "\n";
                pq.pop();
                // 가장 위에 들어가있는 값을 출력
                // pop()을 해주면 queue의 FIFO 성질 때문에 맨위의 값이 나오게 된다.
            }
        } else { // x가 0이 아니라면
            pq.push(x); // 입력한 숫자 queue에 삽입
        }
    }
    return 0;
}