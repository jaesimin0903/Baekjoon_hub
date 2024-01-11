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

    string str;

    cin >> str;
    int ans = 0;
    int max = 0;
    int l = -1;
    bool isClose = false;
    for (int i = 0; i < str.size(); i++) {

        if (str[i] == '(') {
            //if (!s.empty())ans++;

            s.push(str[i]);
            isClose = false;
            max++;
            l++;
        }
        else if (str[i] == ')') {

            if (!s.empty()) {
                if (s.top() == '(') {
                    //cout << s.size() - 1 << "\n";
                    if (!isClose) {
                        //if(s.size()>1)ans--;
                        //cout << "razor" << "\n";
                        ans += (s.size() - 1) ;
                        //cout << ans << "\n";
                    }
                    else {
                        ans++;
                    }
                    isClose = true;
                    s.pop();

                }
            }
        }
    }

    cout << ans;


    return 0;
}
