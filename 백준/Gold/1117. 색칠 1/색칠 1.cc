#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

typedef long long ll;

ll W, H, f, c, x_2, y_2;
ll y_1;
ll x_1;

int main() {

    cin >> W >> H >> f >> c >> x_1 >> y_1 >> x_2 >> y_2;



    ll ans = W * H;

    ll gap = H / (c + 1);


                    ll check;
                    if (2 * f < W) check = f;
                    else check = W - f;
                    if (x_1 <= check && x_2 <= check) {
                        ans -= (c + 1) * ((x_2 - x_1) * (y_2 - y_1));
                    }
                    else if (x_1 <= check && x_2 > check) {
                        ans -= (c + 1) * ((check - x_1) * (y_2 - y_1));
                    }
                    

        ans -= (c+1) *abs(x_2 - x_1) * abs(y_2 - y_1);

    cout << ans;

    return 0;
}