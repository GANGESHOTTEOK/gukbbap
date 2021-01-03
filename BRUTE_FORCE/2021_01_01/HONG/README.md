
# 백준 7568번 [덩치]

---

### 문제 해결 날짜 및 시간

- 2020년 12월 30일
- 메모리 : 2016KB
- 시간 : 88ms

---
```c++
int main(){
	int n;
	int count = 0;
	int title = 665;
	string s;
 
	cin >> n;
 
	while(true){
		s = to_string(++title);

		if (s.find("666") != -1)
			count++;
 
		if (count == n) {
			cout << title << endl;
			break;
		}
	}
 
	return 0;
}
```

6이 3번이상 연속된 수들의 집합중 `n`번째 수를 찾아 출력하는 문제이다.

처음에는 효율성을 위해 666을 `string`화 시켜 사이사이에 수를 넣어 세보려 했다. 하지만 몇번 시도 해보다가 경우가 너무 많고 지져분 해져 최소 숫자 666 부터 1식 카운트 하며 666이 포함되었다면 `title++` 하였다.

`title`을 문자열로 바꾸어 `s`에 저장하고, find 함수를 이용하여 666이 표함되었는지 체크하였다. 666이 포함된 문자열을 확인할 때 마다 `count`가 올라가고 `count`과 `n`이 같아진다면, `count`는 `n`번째 수 이다.