#include <iostream>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> heap1;
int N;
int main(){ios_base::sync_with_stdio(false); cout.tie(NULL); cin.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; ++i){
		int a = 0;
		cin >> a;
		if(!a && heap1.empty())
			cout << 0 << '\n';	
		else if(!a){
			cout << heap1.top() << '\n';
			heap1.pop();
		}
		else
			heap1.push(a);
	}

return 0;
}