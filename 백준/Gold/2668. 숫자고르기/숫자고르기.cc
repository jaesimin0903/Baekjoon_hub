#include <iostream>
#include <vector>
#include <deque>
#include<unordered_set>
#include<algorithm>
using namespace std;

typedef long long ll;
int N, M;
int arr[110];
bool visited[110];
vector<int> ans;

void dfs(int start, int cur){
    if(visited[cur]){
        if(start == cur){
            ans.push_back(cur);
        }
            return;

    }

    visited[cur] = true;
    dfs(start,arr[cur]);
}

int main() {
    cin >> N;

    for(int i =1;i<=N;i++){
        int n1;
        cin >> n1;
        arr[i] = n1;
    }

    for(int i = 1;i<=N;i++){
        fill(&visited[0], &visited[0] + 110, false);
       dfs(i,i);
    }

    cout << ans.size() <<"\n";
    sort(ans.begin(), ans.end());
    for(auto &val : ans){
        cout << val << "\n";
    }

    return 0;
}
