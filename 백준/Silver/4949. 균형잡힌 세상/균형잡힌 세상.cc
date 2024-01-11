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

    string str =" ";
    while (str != ".") {
        getline(cin, str);

        stack<int>s;
        string ans = "yes";
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[' || str[i] == '(') {
                s.push(str[i]);
            }
            else if (str[i] == ']' ) {
                if (s.empty()) {
                    ans = "no";
                    break;
                }
                if (s.top() == '[') {
                    ans = "yes";
                    if(!s.empty())s.pop();
                }
                else {
                    ans = "no";
                    break;
                }
            }
            else if (str[i] == ')') {
                if (s.empty()) {
                    ans = "no";
                    break;
                }
                if (s.top() == '(') {
                    ans = "yes";
                    if (!s.empty())s.pop();
                }
                else {
                    ans = "no";
                    break;
                }
            }
        }
        if (str == ".") break;
        if (s.empty())cout << ans << "\n";
        else cout << "no" << "\n";

    }



    return 0;
}
