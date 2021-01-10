#include <iostream>
#define MAX 10000
using namespace std;

int main(){
	ios_base :: sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

	int N,tmp;
	int num[MAX] = {0,};

	cin >> N;

	for(int i=0;i<N;i++){
		cin >> tmp;
		num[tmp-1]++;
	}

	for(int i=0;i<MAX;i++){
		if(num[i]==1) cout << i+1 << "\n";
		else if(num[i])
			for(int j=0;j<num[i];j++)
				cout << i+1 << "\n";
	}

	return 0;
}