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
string Q;
string A;


int arr[1010];

vector < pair<int,vector<pair<int,string>> > > v;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    //현재위치의 불의 상태가 바뀌는 경우
    //1. 현재위치i를 누를때
    //2. i-1
    //3. i+1

    //111 100 010
    //00000 01110 01001 10101


    cin >> N;

    while (N--) {
        int alpha[30];

        fill(&alpha[0], &alpha[0] + 30, 0);

        int min_val = INT_MAX;
        int max_val = -1;
        string str;
        cin >> str;
        cin >> M;
        int s, e;
        char start;
        for (int i = 0; i < str.size(); i++) {
            alpha[str[i]-'a']++;
            //cout << str[i] - 'a' << " " << alpha[str[i] - 'a'] << "\n";
        }

        for (int i = 0; i < str.size(); i++) {
            if (alpha[str[i] - 'a'] >= M) {
                int count = 0;
                for (int j = i; j < str.size(); j++) {
                    if (str[j] == str[i]) {
                        count++;
                    }
                    if (count == M) {
                        int length = j - i + 1;
                        min_val = min(min_val, length);
                        max_val = max(max_val, length);
                        break;
                    }
                }
            }
        }
        if (max_val != -1) {
            cout << min_val << " " << max_val << '\n';
        }
        else {
            cout << -1 << "\n";
        }
    }



    return 0;
}

