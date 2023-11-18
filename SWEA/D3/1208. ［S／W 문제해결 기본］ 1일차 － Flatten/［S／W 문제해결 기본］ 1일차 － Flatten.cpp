#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;


int main() {
    int TC;
    //cin >> TC;
    TC = 10;
    for (int tc = 1; tc <= TC; ++tc) {
        int N, M;
        
        cin >> N;
        vector<int>v(100, 0);
        for (int i = 0; i < 100; i++) {
            int num;
            cin >> num;
            v[i] = num;
        }
        int dump = 0;

        for (int i = 0; i < N; i++) {
            sort(v.begin(), v.end());
            v[0]++;
            v[v.size() - 1]--;
            dump++;

            if (dump == N)break;
        }

        int max = *max_element(v.begin(), v.end());
        int min = *min_element(v.begin(), v.end());


        cout << "#" << tc << " " << max - min<< "\n";
        
    }



    return 0;
}
