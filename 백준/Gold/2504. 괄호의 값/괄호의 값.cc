#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>
#include<queue>
#include<string>
#include<stack>
using namespace std;

int N, M,T;

int L;


int main() {

    stack<char>s;
    queue<pair<int, int>> a;
    string str;

    cin >> str;
    int ans = 0;
    int num = 1;
    bool isValid = true;
    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            s.push(str[i]);
            num *= 2;
        }
        else if (str[i] == ')') {

            if (!s.empty()) {
                if (str[i - 1] == '(') ans += num;
                if (s.top() == '(') {
                    s.pop();
                    num /= 2;
                }
                else {
                    isValid = false;
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }

        if (str[i] == '[') {
            s.push(str[i]);
            num *= 3;
        }
        else if (str[i] == ']') {

            if (!s.empty()) {
                if (str[i - 1] == '[') ans += num;
                if (s.top() == '[') {
                    s.pop();
                    num /= 3;
                }
                else {
                    isValid = false;
                }
            }
            else {
                cout << 0;
                return 0;
            }
        }
    }

    if (s.empty()) {
        cout << ans;
    }
    else {
        cout << 0;
    }


    return 0;
}
