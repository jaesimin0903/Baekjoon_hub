#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#define MAX 1500001
using namespace std;

typedef long long ll;

vector<int> res;

void dfs(vector<int> v, int idx,int sum, int a, int b, int c, int d) {
    if (idx == v.size() ) {
        res.push_back(sum);
        return;
    }

    if (a > 0) {
        dfs(v, idx + 1, sum + v[idx], a-1, b, c, d);
    }
    if (b > 0) {
        dfs(v, idx + 1, sum - v[idx], a, b-1, c, d);
    }
    if (c > 0) {
        dfs(v, idx + 1, sum * v[idx], a, b, c-1, d);
    }
    if (d > 0) {
        dfs(v, idx + 1, sum / v[idx], a, b, c, d-1);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    int n;
    cin >> n;
    int num;
    int a, b, c, d;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        cin >> num;
        v.push_back(num);
    }

    cin >> a >> b >> c >> d;
    dfs(v, 1, v[0], a, b, c, d);
    
    int minn = *min_element(res.begin(), res.end());
    int maxx = *max_element(res.begin(), res.end());

    cout << maxx << "\n";
    cout << minn << "\n";

    return 0;
}
