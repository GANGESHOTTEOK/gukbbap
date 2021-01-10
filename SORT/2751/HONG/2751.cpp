#include <iostream>
#include <queue>
using namespace std;
#define MAXVALUE 1000000

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,max = 0;
	int rdxarr[MAXVALUE];
	queue<int> digits[10];

	cin >> N;

	for(int i=0;i<N;i++) {
		cin >> rdxarr[i];
		rdxarr[i] += MAXVALUE;
		max = rdxarr[i] > max ? rdxarr[i] : max;
	}

	int radix = 1;

	while((max/radix) > 0){
		for(int i=0;i<N;i++)
			digits[(rdxarr[i] / radix) % 10].push(rdxarr[i]);

		int idx = 0; 	

		for(int i=0;i<10;i++){
			while(!digits[i].empty()){
				rdxarr[idx++] = digits[i].front();
				digits[i].pop();
			}
		}
		radix*=10;
	}

	for(int i=0;i<N;i++){
		rdxarr[i] -= MAXVALUE;
		cout << rdxarr[i] << '\n';
	}
	
	return 0;
}