#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <climits>
using namespace std;

int N, X;

int A;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    cin >> N >> X;
    vector<int> arr;
    for (int i = 0; i < N; i++) {
        cin >> A;
        if (A < X) arr.push_back(A);
    }

    for(int i = 0;i<arr.size();i++)
    {
        cout << arr[i] << " ";
    }
    

    return 0;
}
