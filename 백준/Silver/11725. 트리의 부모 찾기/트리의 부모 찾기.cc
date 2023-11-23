#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cmath>
#include <set>
using namespace std;

long long N, M;
int choose[10];


int num[1001];
int dp[1001];
int main (){
    cin >> N ;

    vector<vector<int>> tree(N+1,vector<int>());
    int parent[N+1];
    queue<int> q;
    bool visited[100001]={false,};
    for(int i =0 ;i<N-1;i++){
        int n1, n2;
        cin >> n1>> n2;
        tree[n1].push_back(n2);
        tree[n2].push_back(n1);
    }

    for(int i = 0;i<tree[1].size();i++){
        q.push(tree[1][i]);
        parent[tree[1][i]] = 1;
        visited[tree[1][i]] = true;
    }

    while(!q.empty()){
        int node = q.front();
        q.pop();
        if(tree[node].size()==0) continue;
        for(int i = 0;i<tree[node].size();i++){
            if(visited[tree[node][i]]) continue;
            q.push(tree[node][i]);
            parent[tree[node][i]] = node;
            visited[tree[node][i]] = true;
        }
    }

    for(int i = 2;i<=N;i++){
        cout << parent[i] << "\n";
    }

    return 0;
}