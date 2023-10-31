#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;


int main() {

    int n;
    cin >> n;
    vector<pair<int, int>> v;
    int room = 0;
    vector<bool> visited;

    for (int i = 0; i < n; i++) {
        int a;
        int b;
        cin >> a >> b;
        v.push_back({ a,b });
        visited.push_back(false);
    }

    // 첫 번째 원소를 기준으로 오름차순 정렬하고, 
    // 첫 번째 원소가 같을 경우 두 번째 원소로 오름차순 정렬
    sort(v.begin(), v.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
        if (a.first == b.first) {
            return a.second < b.second;
        }
        return a.first < b.first;
        });

    priority_queue<int, vector<int>, greater<int>>pq;

    pq.push(v[0].second);
    for (int i = 1; i < n; i++) {
        pq.push(v[i].second);
        if (pq.top() <= v[i].first) {
            pq.pop();
        }
    }

    cout << pq.size();
    return 0;
}
