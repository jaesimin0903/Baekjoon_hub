#include <iostream>
#include <list>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;
    cin >> N >> K;
    vector<int> ans;
    list<int> lst;
    for (int i = 1; i <= N; i++) {
        lst.push_back(i);
    }

    auto t = lst.begin();
    while (!lst.empty()) {
        for (int i = 0; i < K - 1; i++) {
            t++;
            if (t == lst.end()) {
                t = lst.begin();
            }
        }

        ans.push_back(*t);
        t = lst.erase(t);
        if (t == lst.end() && !lst.empty()) {
            t = lst.begin();
        }
    }

    cout << "<";
    for (size_t i = 0; i < ans.size(); i++) {
        cout << ans[i];
        if (i != ans.size() - 1) {
            cout << ", ";
        }
    }
    cout << ">" << endl;

    return 0;
}
