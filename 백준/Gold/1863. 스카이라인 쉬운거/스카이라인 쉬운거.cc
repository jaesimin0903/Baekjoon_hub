#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int arr[50010];

int main() {
    int N;
    cin >> N;
    fill(&arr[0], &arr[0] + 50010, -1);
    stack<int> s;
    int top = 0;
    int ans = 0;
    for (int i = 0; i < N; i++) {
        int n1, n2;
        if (i != N) {
            cin >> n1 >> n2;
        }
        else n2 = 0;
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
        //cout << ans << "\n";
    }

    while (!s.empty()) {
        //cout << "not empty" << "\n";
       ans++;
        s.pop();
    }


    cout << ans;

    return 0;
}
