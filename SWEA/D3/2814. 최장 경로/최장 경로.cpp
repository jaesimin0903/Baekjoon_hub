
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
vector<bool> visited(20);
int answer =0 ;
void dfs(unordered_map<int, vector<int>> &um,int num, int sum){
	answer = max(answer, sum);
    //cout << num << " " << sum << "\n";
    for(int i = 0;i<um[num].size();i++){
        if(visited[um[num][i]]) continue;
        visited[um[num][i]] = 1;
        dfs(um, um[num][i], sum+1);
        visited[um[num][i]] = 0;
    }
}

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;
	/*
	   여러 개의 테스트 케이스가 주어지므로, 각각을 처리합니다.
	*/
	for(test_case = 1; test_case <= T; ++test_case)
	{

		int N, M;
        cin >> N >> M;
        unordered_map<int, vector<int>> um;
        visited.clear();
        for(int i =0;i<M;i++){
            int n1;
            cin >> n1;
            int n2;
            cin >> n2;
            um[n1].push_back(n2);
            um[n2].push_back(n1);
        }
        for(int i = 1;i<=N;i++){
            visited[i] = 1;
            dfs(um, i, 1);
            visited[i] = 0;
        }
        cout << "#" << test_case << " " << answer << "\n";
        answer = 0;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}