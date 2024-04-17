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
#include<cstring>
using namespace std;

int board[21][21];
int eat = 0;
int ssize = 2;
int N;
int ans = 0;

int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    vector<string> v;

    for (int i = 0; i < N; i++) {
        string str;
        cin >> str;
        v.push_back(str);
    }

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        if (a.size() != b.size()) {
            return a.size() < b.size();
        }
        int a_sum = 0;
        int b_sum = 0;
        bool is_a_num = false;
        bool is_b_num = false;
        for (int i = 0; i < a.size(); i++) {
            if ('0' <= a[i] && a[i] <= '9') {
                a_sum += a[i]- '0';
                is_a_num = 1;
            }
            if ('0' <= b[i] && b[i] <= '9') {
                b_sum += b[i]-'0';
                is_b_num = 1;
            }
        }
        //cout << a_sum << " " << b_sum << "\n";
        if (is_a_num || is_b_num) {
           if(a_sum != b_sum) return a_sum < b_sum;
           if (a_sum == b_sum)
               for (int i = 0; i < a.size(); i++) {
                   if (a[i] != b[i]) return a[i] < b[i];
               }
        
        }

        if (a_sum == b_sum)
            for (int i = 0; i < a.size(); i++) {
                if (a[i] != b[i]) return a[i] < b[i];
            }
        });
        

    for (auto& s : v) {
        cout << s << "\n";
    }

    return 0;
}

