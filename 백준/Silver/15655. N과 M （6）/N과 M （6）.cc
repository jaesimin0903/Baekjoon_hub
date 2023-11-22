#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

void dfs(vector<bool>& visited, vector<int> &ans,vector<int> &v,int idx, int count){
    if(count == M){
        for(auto&val :ans){
            cout << val << " ";
        }
        cout << "\n";
        return;
    }
    for(int i = 0;i<N;i++){
        if(visited[i]) continue;
        if(v[i] < v[idx])continue;
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
    for(int i = 0;i<N;i++){
        vector<bool> visited(N+1,false);
        vector<int> ans;
        visited[i] = true;
        ans.push_back(v[i]);
        dfs(visited,ans, v,i, 1);    
    }
    
    return 0;
}