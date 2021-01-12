#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#define FOR(i, n) for (int i = 0; i < n; i++)
using namespace std;

struct People {
    int id;
    int age;
    string name;
};

bool compare(People & person1, People & person2) {
    if (person1.age == person2.age) return person1.id < person2.id;
    return person1.age < person2.age;
}

int main(void) {
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int num; cin >> num;
    vector <People> peopleList(num);
    FOR(i, num) {
        peopleList[i].id = i;
        cin >> peopleList[i].age >> peopleList[i].name;
    }
    sort(peopleList.begin(), peopleList.end(), compare);
    FOR(i, num) cout << peopleList[i].age << " " << peopleList[i].name << "\n";
    return 0;
}

