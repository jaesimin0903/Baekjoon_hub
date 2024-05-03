#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
#include <tuple>
#include <cmath>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include<cstring>
#include<iomanip>
using namespace std;

typedef long long ll;

int N,M;

int arr[1010];

vector < pair<int,vector<pair<int,string>> > > v;

int find_room(int level){
    bool is_here = false;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].first -10<= level && v[i].first + 10 >= level) {
            if(v[i].second.size() < M) return i;
        }
    }
    return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        int level;
        string name;
        cin >> level >> name;
        int idx = find_room(level);
        if (idx != -1 && v[idx].second.size() < M) {
            v[idx].second.push_back({ level,name });
        }
        else {
            vector<pair<int, string>> part;
            part.push_back({ level,name });
            v.push_back({ level,part });
        }
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].second.size() == M) {
            cout << "Started!" << "\n";
        }
        else {
            cout << "Waiting!" << "\n";
        }
        sort(v[i].second.begin(), v[i].second.end(), [](pair<int,string>& a, pair<int,string>& b) {
            if (a.second != b.second) return a.second < b.second;
            });
        for (int j = 0; j < v[i].second.size(); j++) {
            cout << v[i].second[j].first << " " << v[i].second[j].second << "\n";
        }
    }
 
    return 0;
}

