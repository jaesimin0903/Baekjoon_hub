#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

int N, M, S, E;

unordered_map<int, vector<int>> um;

bool visited[1010];

void visited_clear(){
	for(int i = 0;i<1010;i++){
		visited[i] = false;
	}
}

int main() {
	
	cin >> N >> M >> S >> E;
	
	for(int i =0;i<M;i++){
		int n1, n2;
		cin >> n1 >> n2;
		um[n1].push_back(n2);
		um[n2].push_back(n1);
	}
	
	for(int i = 1;i<=N;i++){
		visited_clear();
		visited[i] = true;
		
		if(visited[S]){
			cout << -1 << "\n";
			continue;
		}
		int ans = 2000000000;
		int s = 0;
		queue<pair<int,int>> q;
		q.push({S,1});
		visited[S] = 1;
		bool is_ok = false;
		while(!q.empty()){
			int cur = q.front().first;
			int lang = q.front().second;
			q.pop();
			
			
			
			if(cur == E){
				ans = min(ans, lang);
				is_ok = true;
			}
			
			for(int j = 0;j<um[cur].size();j++){
				if(visited[um[cur][j]])continue;
				q.push({um[cur][j],lang+1});
				visited[um[cur][j]] = true;
			}
		}
		
		if(!is_ok)cout << -1 << '\n';
		else cout << ans << "\n";
	}
	
}