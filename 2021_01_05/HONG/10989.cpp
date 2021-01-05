#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int num;
	int data[10000000];

	cin >> num;

	for(int i = 0; i < num; i++){
		cin >> data[i];
	}
	data[num] = 0;



	for(int i = num-1;i>0;i--){
		swap(data[i],data[0]);
		heap_generator(data,i);
	}
	
	for(int i=0; i<num; i++) 
		cout << data[i] << endl;
    
}

void heap_generator(int *data, int num){

	for(int i=1; i<num; i++){
		int child = i;
			
		while(child>0){
			int root = (child - 1)/ 2;

			if(data[root] > data[child]){
				swap(data[root],data[child]);
			}

			child = root;
		}
	}
}