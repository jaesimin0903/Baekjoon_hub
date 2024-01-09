#include <iostream>
#include <vector>
#include <algorithm>
#include <limits.h>
#include <deque>

using namespace std;

int N, M;

int main() {
    deque<int> d;

    vector<int> ans;

    cin >> N >> M;

    for (int i = 0; i < N; i++) {
        d.push_back(i + 1);
    }

    for (int i = 0; i < M; i++) {
        int num;
        cin >> num;
        ans.push_back(num);
    }
    int a = 0;
    int idx = 0;
    // 1 2 3 4 5 6 7 8 9 10
    //1
    // 2 3 4 5 6 7 8 9 10
    // 9
    // 10 2 3 4 5 6 7 8
    //target point 가 front, back 과 의 거리비교를 통해 방법을 정한다.
    while (idx != M) {
        if (d.front() == ans[idx]) {
            d.pop_front();
            idx++;
        }
        else {
            int ans_idx = 0;
            for (int i = 0; i < d.size(); i++) {
                if (d[i] == ans[idx]) ans_idx = i;
            }
            int f_gap = abs(0 - ans_idx);
            int b_gap = abs((int)d.size() - ans_idx -1);

            //뒤쪽에서 빼오기
            if (f_gap > b_gap) {
                d.push_front(d.back());
                d.pop_back();
            }
            else {
                d.push_back(d.front());
                d.pop_front();
            }

            a++;

        }


    }

    cout << a;
    

    return 0;
}
