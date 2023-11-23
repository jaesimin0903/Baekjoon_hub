#include <iostream>
#include <queue>
#include <set>
using namespace std;

struct Data{
    int dist;
    long num;
    Data(int _dist, long _num) : dist(_dist), num(_num){}
};

int main() {
    int A, B;
    cin >> A >> B;

    queue<Data> que;
    set<int> visit;

    que.push({1, A});

    while (!que.empty()){
        Data current = que.front();
        que.pop();

        if(visit.find(current.num) != visit.end() || current.num > B)
            continue;
        if(current.num == B){
            cout << current.dist << endl;
            return 0;
        }

        visit.insert(current.num);

        que.push({current.dist + 1, current.num * 2});
        que.push({current.dist + 1, current.num * 10 + 1});
    }

    cout << -1 << endl;
    return 0;
}