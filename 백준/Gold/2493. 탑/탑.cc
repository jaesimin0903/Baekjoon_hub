#include <iostream>
#include <list>
#include <vector>
#include <stack>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int N, K;

    stack<pair<int,int>> s;
    stack<pair<int, int>> a;
    cin >> N;
    vector<int> ans(500001, 0);

    for (int i = 1; i <= N; i++) {
        int n;
        cin >> n;
        s.push({ i,n });
    }

    while (!s.empty()) {
        if (a.empty()) {
            a.push(s.top());
            s.pop();
        }

        if (s.empty()) {
            break;
        }

        if (s.top().second >= a.top().second) {
            //cout <<s.top() << " "<<a.top() << s.size()<< " pop" << "\n";
            
            if (!a.empty()) { 
                ans[a.top().first] = s.top().first;
                a.pop(); }
        }
        else {
            //cout << s.top() << " " << a.top() << " ?" << "\n";
            a.push(s.top());
            s.pop();
        }

        
    }

    for (int i = 1; i <= N; i++) {
        cout << ans[i] << " ";
    }


    return 0;
}
