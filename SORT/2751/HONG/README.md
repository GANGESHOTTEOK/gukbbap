
# 백준 2751번 문제 [수정렬하기 2]

---

### 문제 해결 날짜 및 시간

- 2021년 1월 4일 22시
- 메모리 : 10272KB
- 시간 : 272ms

---

### 접근 방식

```cpp
#define MAXVALUE 1000000
//자연수의 범위

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N,max = 0;
	int rdxarr[MAXVALUE];
    //N개의 배열을 저장할 배열
	queue<int> digits[10];
    // 각 자리수 안에서 counting sort하여 저장할 큐 배열(10)

	cin >> N;

	for(int i=0;i<N;i++) {
		cin >> rdxarr[i];
    
		rdxarr[i] += MAXVALUE;
        //입력받음과 동시에 음수도 비교하기위해 MAXVALUE를 더한다
		max = rdxarr[i] > max ? rdxarr[i] : max;
        // 최댓값을 max에 저장
	}

	int radix = 1;
    //정렬할 자리수를 의미

	while((max/radix) > 0){
        //최댓값 / 현재 정렬하는 자리수가 0보다 클때까지

		for(int i=0;i<N;i++)
			digits[(rdxarr[i] / radix) % 10].push(rdxarr[i]);
            // (숫자 / 자리수)%10 => 자리수 에 해당하는 digits 큐에 넣는다

		int idx = 0; 	
        //큐에서 뺀 수를 배열에 순서대로 갱신하기 위한 인덱스

		for(int i=0;i<10;i++){

			while(!digits[i].empty()){
                // 한 digit(큐)가 모두 빌때까지

				rdxarr[idx++] = digits[i].front();
				digits[i].pop();
                // 넣었던 큐를 빼서 배열에 다시 순서대로 집어 넣어 배열을 갱신한다.
			}
		}
		radix*=10;
        // radix 자리수의 정렬이 끝나면 다음 radix로 이동 (X10)
	}

	for(int i=0;i<N;i++){
		rdxarr[i] -= MAXVALUE;
		cout << rdxarr[i] << '\n';
        // 최댓값의 최대자리수 까지 정렬이 끝나고 더했던 MAXVALUE 값을 다시 빼주고 출력한다
	}
	
	return 0;
}
```

평범한 정렬대신 `Radix Sort` 기수정렬(LSD)로 풀어 보았다. 

기수정렬이란 `Counting Sort` 와 유사한데 각 자리수들을 0부터 9까지 해당하는 배열에 넣을 수 있게 큐를 만들어 넣는 것이다. 가장 낮은 자리수부터 시작하여 0~9까지만 계수정렬하는 것이다. 그 후 큐배열을 순회하며 차례대로 뺀 다음 다시 배열에 순서대로 저장하면, 큐는 `FIFO` 선입선출이므로 1의 자리수 순으로 정렬 되어있을 것이다. 

이런 식으로 낮은 자리 수 부터 가장 높은 자리 수 까지 각 자리를 0~9까지에 계수정렬하면 비교하지 않고 안정성을 가진(`stable`) 기수정렬을 할 수 있다.

처음에는 계수정렬의 메모리 낭비를 보완한 상위호환 버전이구나 라고 생각하였는데 그건 또 아닌 것 같다.

복잡도를 생각 해볼때 `O(d(n+k))` 이다. d는 최대 자리수이고, n+k인 이유는 내부정렬이 아니라 외부정렬이기 때문에 큐에서 넣고 빼서 임시로 저장할 배열이 필요하기 떄문이다. 이 문제에서는 `n` >> `k`(0~9까지 이므로 상수 10) 이므로 `O(5(N+10))`.

![LSD](https://miro.medium.com/max/4800/0*BmW0Io1fGRrKkigM)