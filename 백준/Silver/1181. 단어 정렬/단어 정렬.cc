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
using namespace std;

typedef long long ll;

int N;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> N;
    vector<string> v;

    for (int i = 0; i < N; i++) {
        string num;
        cin >> num;
        
        v.push_back(num);
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) return a.size() < b.size();
        return a < b;
        });

    v.erase(unique(v.begin(), v.end()), v.end());

    for (auto val : v) {
        cout << val << "\n";
    }
    return 0;
}

