#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;
int choose[10];
vector<vector<int>> ansList;

void dfs(vector<bool>& visited, vector<int> &ans,vector<int> &v,int idx, int count){
    if(count == M){
        for(int i = 0;i<M;i++){
            cout << ans[i] << " ";
        }
        cout << "\n";
        return;
    }
    int pre = -1;
    for(int i = 0;i<N;i++){
        //if(visited[i]) continue;
        if(pre == v[i]) continue;
        pre = v[i];
        if(ans.size() > 0 &&v[i] < ans[ans.size()-1])continue;
        visited[i] = true;
        ans.push_back(v[i]);
        dfs(visited,ans,v, i, count+1);
        visited[i] = false;
        ans.pop_back();
    }
}
int main (){
    cin >> N >> M;

    vector<int> v;
    for(int i =0;i<N;i++){
        int n;
        cin >> n;
        v.push_back(n);
    }
    sort(v.begin(),v.end());
    vector<bool> visited(N+1,false);
        vector<int> ans;
    dfs(visited,ans, v,0, 0); 

    return 0;
}