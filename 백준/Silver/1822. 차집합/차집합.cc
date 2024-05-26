#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int nA, nB;

int A[500010];
int B[500010];

int main() {
    cin >> nA >> nB;

    vector<int> ans;

    for (int i = 0; i < nA; i++) {
        cin >> A[i];
    }

    for (int i = 0; i < nB; i++) {
        cin >> B[i];
    }

    sort(A, A + nA);
    sort(B, B + nB);

    for (int i = 0; i < nA; i++) {
        if (!binary_search(B, B + nB, A[i]))ans.push_back(A[i]);
    }
    if (ans.size() == 0) {
        cout << 0;
        return 0;
    }
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }

    return 0;
}
