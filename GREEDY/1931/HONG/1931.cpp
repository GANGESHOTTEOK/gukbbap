#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

int main(){
    int N,tmp_srt,tmp_end;
    typedef vector<pair<int,int> > time;
    time session;

    cin >> N;
    for(int i=0;i<N;i++){
        cin >> tmp_srt >> tmp_end;
        session.push_back(make_pair(tmp_end,tmp_srt));
    }

    sort(session.begin(),session.end());

    int cnt = 1, last = session[0].first;
    for(int i=1;i<N;i++)
        if(session[i].second >= last) {
            cnt++;
            last = session[i].first;
        }
    cout << cnt;

    return 0;
}