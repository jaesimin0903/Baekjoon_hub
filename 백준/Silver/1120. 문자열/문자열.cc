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

int N, K;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str1, str2;

    cin >> str1 >> str2;
    int answer = 9999;
    for (int i = 0; i < str2.size() - str1.size()+1; i++) {
        int cnt = 0;
        for (int j = 0; j < str1.size(); j++) {
            if (str2[i + j] != str1[j]) cnt++;
        }
        answer = min(cnt, answer);
    }
    cout << answer;
    return 0;
}
