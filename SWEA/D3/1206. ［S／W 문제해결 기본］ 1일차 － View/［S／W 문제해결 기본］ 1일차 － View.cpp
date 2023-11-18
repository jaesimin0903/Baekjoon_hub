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
        int ans = 0;
        
        vector<int> v(N,0);
        vector<bool> isAvail(N,true);

        for (int i = 0; i < N; i++) {
            int num;
            cin >> num;
            v[i] = num;
        }
        int peak = 0;
        int upcnt = 0;
        int downcnt = 0;
        for (int i = 2; i < N-2; i++) {
            //오르막 혹은 내리막을 판단
            int t =1;
            int maxx = 0;
            if (isAvail[i]) {
                while (t <=2) {
                    if (v[i] > v[i - t]) {
                        isAvail[i - t] = false;
                        if (maxx < v[i - t]) maxx = v[i - t];
                    }
                    else {
                        isAvail[i] = false;
                        break;
                    }
                    if (v[i] > v[i + t]) {
                        isAvail[i + t] = false;
                        if (maxx < v[i + t]) maxx = v[i + t];
                    }
                    else {
                        isAvail[i] = false;
                        break;
                    }
                    t++;
                }

                if (isAvail[i]) {
                    ans += v[i] - maxx;
                }
            }
            
        }
        

        cout << "#" << tc << " " << ans<< "\n";
    }

    return 0;
}
