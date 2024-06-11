#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

int N, K, P, X;

string num[10] = {
    "1101111","0101000","1110110","1111100","0111001","1011101","1011111","1101000","1111111","1111101"
};

int main() {

    cin >> N >> K >> P >> X;

    int ten = 10;
    int ans = 0;
    int target;

    

    for (int i = 1; i <= N; i++) {
        string target = to_string(i);
        string x = to_string(X);
        if (x != target) {
            if (x.size() > target.size()) {
                while (x.size() != target.size()) {
                    target = '0' + target;
                }

            }
            else if (x.size() < target.size()) {
                while (x.size() != target.size()) {
                    x = '0' + x;
                }
            }


            int sum = 0;
            for (int j = 0; j < x.size(); j++) {
                int num1 = x[j] - '0';
                int num2 = target[j] - '0';
                //cout << num1 << " " << num2 << "\n";
                for (int k = 0; k < 7; k++) {
                    if (num[num1][k] != num[num2][k]) sum++;
                }

            }

            //cout << sum << "\n";

            if (sum <= P) {
                //cout << i << "\n"; 
                ans++;
            }

        }
    }

    cout << ans;

    return 0;
}
