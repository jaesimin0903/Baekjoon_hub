#include <iostream>
#include <vector>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int>> q;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, m;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int n;
        cin >> n;
        if (n == 0) {
            if (q.empty()) {
                cout << 0 << "\n";
            }
            else {
                cout << q.top()<< "\n";
                q.pop();
            }
        }
        else {
            q.push(n);
        }
    }
    return 0;
}
