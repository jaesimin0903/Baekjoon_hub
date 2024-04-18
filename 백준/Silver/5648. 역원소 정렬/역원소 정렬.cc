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
    vector<ll> v;

    for (int i = 0; i < N; i++) {
        string num;
        cin >> num;
        ll sum = 0;
        int s = num.size();
        for (int j = 0; j < num.size(); j++) {
            sum += (num[num.size() - j -1]-'0') * pow(10, s - 1);
            s--;
        }
        v.push_back(sum);
    }

    sort(v.begin(), v.end());

    for (auto val : v) {
        cout << val << "\n";
    }
    return 0;
}

