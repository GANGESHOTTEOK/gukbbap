#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int a[1000] = {0,};
    int N;

    cin >> N;

    for(int i=0;i<N;i++)
        cin >> a[i];
    
    sort(a,a+N);

    for(int i=0;i<N;i++) 
        cout << a[i] << endl;

    return 0;
}


#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;

void heap_generator(vector<int> *data, int num){
	
	for(int i=1; i<num; i++){
		int child = i;
			
		while(child>0){
			int root = (child - 1)/ 2;
			 
			if((*data)[root] > (*data)[child]){
				swap((*data)[root],(*data)[child]);
				child = root;
			}
			else break;
		}
	}
}

int main() {
	int num,tmp;
	vector<int> data;

	scanf("%d",&num);
	
	for(int i = 0; i < num; i++){
		scanf("%d",&tmp);
		data.push_back(tmp);
	}

	data.push_back(0);

	heap_generator(&data,num);

	

	for(int i = num-1;i>0;i--){

		swap(data[i],data[0]);
		printf("switch %d %d \n",data[i],data[0]);

		int root = 0;
		int child = 0;
			
		while(root<i){
			if(root*2+2 < i+1 && i+1 < root*2+1) 
				child = root*2+2;

			else if(root*2+1 < i+1 && i+1 < root*2+2)
				child = root*2+1;
			
			else if(root*2+1 < i+1 && i+1 > root*2+2) {
				child = data[root*2+1] <= data[root*2+2] ? root*2+1 : root*2+2;
			}
			else {
				printf("stop1\n");
				break;
			
			}
			
			
			printf("i= %d root %d %d childs %d\n",i,data[root],root,child);

			if(data[root] > data[child]){
				swap(data[root],data[child]);
				root = child;
			}
			else {
				printf("stop2\n");
				break;
			
			}
		}

	}
	
	for(int i = num-1; i>=0; i--) {
		printf("%d\n",data[i]);
	}
	return 0;
}
