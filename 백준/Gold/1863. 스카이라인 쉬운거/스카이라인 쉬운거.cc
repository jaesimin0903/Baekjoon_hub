#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;


int main() {
    int N;
    cin >> N;

    stack<int> s;

    int ans = 0;
    for (int i = 0; i < N; i++) {
        int n1, n2;
        cin >> n1 >> n2;
        if (s.empty()) {
            if(n2 != 0)s.push(n2);
        }
        else {
            if (s.top() >= n2) {
                while (!s.empty() && s.top() > n2) {
                    s.pop();
                    ans++;
                }
                if (s.empty() || s.top() < n2) if(n2 != 0)s.push(n2);
            }
            else {
                s.push(n2);
            }
        }

    }

    while (!s.empty()) {
       ans++;
        s.pop();
    }


    cout << ans;

    return 0;
}
