#include <iostream>
#include <unordered_map>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N, M, K;

unordered_map<int, vector<int>> um;
bool visited[10010];
int leng[10010];
int main() {

	cin >> N >> M >> K;
	
	for(int i = 0;i<M;i++){
		int n1, n2;
		cin >> n1 >> n2;
		um[n1].push_back(n2);
	}
	
	leng[K] = -1;
	
	queue<pair<int,int>> q;
	q.push({K,0});
	visited[K] = 1;
	
	while(!q.empty()){
		int cur, size;
		cur = q.front().first, size = q.front().second;
		
		q.pop();
		
		for(int i = 0;i<um[cur].size();i++){
			if(visited[um[cur][i]])continue;
			if(leng[um[cur][i]] != 0)leng[um[cur][i]] = min(leng[um[cur][i]], abs(K-um[cur][i])+size+1);
			else leng[um[cur][i]] = abs(K-um[cur][i])+size+1;
			//cout << leng[um[cur][i]] << "\n";
			q.push({um[cur][i], size+1});
			visited[um[cur][i]] = true;
		}
	}
	
	int ans  = -1;
	int point = -1;
	vector<pair<int,int>> v;
	for(int i = 1;i<=N;i++){
		v.push_back({leng[i], i});
	}
	
	sort(v.begin(), v.end(), [](const auto &a, const auto &b){
		if(a.first != b.first) return a.first > b.first;
		return a.second > b.second;
	});
	
	if(v[0].first != 0) cout << v[0].second;
	else cout << -1;
	
	for(auto & val : v){
		//cout << val.first << " " << val.second << "\n";
	}

	
	return 0;
}