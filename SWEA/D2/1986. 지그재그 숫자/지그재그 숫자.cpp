#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    int TC;
    cin >> TC;

    for (int tc = 1; tc <= TC; ++tc) {
        int N, M;
        //cin >> N >> M;
        cin >> N;

        int sum = 1;
        for (int i = 2; i <= N; i++) {
            if (i % 2 == 0) {
                sum -= i;
            }
            else {
                sum += i;
            }
        }
        

        cout << "#" << tc << " " << sum << endl;
    }

    return 0;
}
