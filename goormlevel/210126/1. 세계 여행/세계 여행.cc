#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int, vector<int>> um;

int N,M;
int lang[1010];
		bool visited[1010];
int main() {

	//각 나라는 1~N 1에서 시작
	//서로다른 두나라 항로 M개
	//그래프
	//언어 10개
	//1, 추가적인 언어1개
	//맵을 이용한 그래프 인잇
	
	cin >> N >> M;
	
	for(int i =1;i<=N;i++){
		cin >> lang[i];
	}
	
	for(int i =0;i<M;i++){
		int n1, n2;
		cin >> n1 >> n2;
		um[n1].push_back(n2);
		um[n2].push_back(n1);
	}
	
	
	int ans = 0;
	for(int i = 1;i<=10;i++){
		for(int idx = 1;idx <= N;idx++){
			visited[idx] = false;
		}
		visited[1] = 1;
		queue<int> q;
		q.push(1);
		int s = 0;
		while(!q.empty()){
			int cur = q.front();
			q.pop();
			s++;
			for(int j = 0;j<um[cur].size();j++){
				int nxt = um[cur][j];
				if(lang[nxt] != i && lang[nxt] != lang[1])continue;
				if(visited[nxt]) continue;
				q.push(nxt);
				visited[nxt] = 1;
			}
		}
		ans = max(ans, s);
	}
	cout << ans;
	return 0;
}