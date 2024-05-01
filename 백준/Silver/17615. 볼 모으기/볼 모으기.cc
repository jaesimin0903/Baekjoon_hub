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

int N, K;

ll arr[200010];
ll cnt[100010];
ll m[510][510];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;

    string str;
    cin >> str;

    int answer = 0;
    char start_char;
    if (str[N - 1] == 'R') start_char = 'R';
    else start_char = 'B';
    bool flag = false;
    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) flag = false;

        if (flag && str[i] == start_char) answer++;
        else if (!flag && str[i] != start_char) flag = true;
    }

    if (start_char == 'R') start_char = 'B';
    else start_char = 'R';

    int part = 0;

    for (int i = N - 1; i >= 0; i--) {
        if (i == N - 1) flag = false;

        if (flag && str[i] == start_char) part++;
        else if (!flag && str[i] != start_char) flag = true;
    }

    answer = min(part, answer);
    cout << answer;
    
    return 0;
}
