#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N;
int people[70][10];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++) {
        for (int j = 1; j < 10; j++) {
            cin >> people[i][j];
        }
    }

    vector<int> arr = { 2, 3, 4, 5, 6, 7, 8, 9 }; // 1번 선수를 제외한 나머지 타자들
    int ans = 0;

    do {
        vector<int> lineup = { arr[0], arr[1], arr[2], 1, arr[3], arr[4], arr[5], arr[6], arr[7] };
        int part = 0;
        int cur = 0;

        for (int i = 0; i < N; i++) {
            int out = 0;
            int base[3] = { 0, 0, 0 };

            while (out < 3) {
                int action = people[i][lineup[cur]];
                if (action == 0) {
                    out++;
                }
                else if (action == 1) {
                    part += base[2];
                    base[2] = base[1];
                    base[1] = base[0];
                    base[0] = 1;
                }
                else if (action == 2) {
                    part += base[2] + base[1];
                    base[2] = base[0];
                    base[1] = 1;
                    base[0] = 0;
                }
                else if (action == 3) {
                    part += base[2] + base[1] + base[0];
                    base[2] = 1;
                    base[1] = base[0] = 0;
                }
                else if (action == 4) {
                    part += base[2] + base[1] + base[0] + 1;
                    base[2] = base[1] = base[0] = 0;
                }

                cur++;
                if (cur >= 9) cur = 0;
            }
        }

        ans = max(ans, part);

    } while (next_permutation(arr.begin(), arr.end()));

    cout << ans;

    return 0;
}
