
#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

//dfs로 n을 나눌 수있는 모든 경우의 수를 찾기
//생성된 경우를 벡터화하고 사이즈가 11개 될때까지 0 추가
//permutation 을 이용해 모든 경우 탐색

int N;
int maxx = 0;
vector<int> ans;
vector<int> information;
void dfs(int num, int cur, vector<int>& vec) {
    if (num == 0) {
        

        vector<int>copy = vec;
        while (copy.size() < 11) {
            copy.push_back(0);
        }
        int val = 0;
        int val2 = 0;

        sort(copy.begin(), copy.end());
        //for (auto& val : copy) {
        //                        cout << val << " ";
        //                    }
        //                    cout << "\n";
        do {
            
            for (int i = 0; i < copy.size(); i++) {
                //cout << copy[i] << " ";


                if (copy[i] > information[i]) val += 10 - i;
                else if (information[i] != 0 && copy[i] <= information[i])val2 += 10 - i;
            }
            if (maxx < abs(val - val2) && val > val2) {
                maxx = abs(val - val2);
                ans = copy;
            }
            else if (maxx == abs(val - val2) && val > val2) {
                vector<int> tmp = { 1,1,0,1,0,0,0,0,0,0,0 };
                //if (ans == tmp) cout << "here";
                for (int i = 10; i >= 0; i--) {
                    if ( ans[i] < copy[i]) {
                        ans = copy;
                        break;
                    }
                    else if(ans[i] > copy[i]) {
                        break;
                    }
                }
            }
            val = 0; val2 = 0;

            //cout << "\n";
        } while (next_permutation(copy.begin(), copy.end()));


        return;
    }
    if (num > 0 && vec.size() == 11) {
        return;
    }

    for (int i = cur; i <= num; i++) {
        if (num - i >= 0) {
            vec.push_back(i);
            dfs(num - i, i, vec);
            vec.pop_back();
        }
    }
}

vector<int> solution(int n, vector<int>info) {
    vector<int> answer;
    //nC11
    N = n;
    information = info;


    for (int i = 1; i <= N; i++) {
        vector<int>v;
        v.push_back(i);
        dfs(n - i, i, v);
    }

    answer = ans;


    if (answer.size() == 0) return { -1 };
    return answer;
}
