#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;

int N, M;

unordered_map<int, int>um;

bool binarySearch(vector<int>& A, int x, int left, int right) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2;

    if (A[mid] == x) {
        return true;
    }
    else if (A[mid] > x) {
        return binarySearch(A, x, left, mid - 1);
    }
    else {
        return binarySearch(A, x, mid + 1, right);
    }
}

int main() {
    
    cin >> N ;
    vector<int>A;
    vector<int> X;
    for (int i = 0; i < N; i++) {
        int n1;
        cin >> n1;
        A.push_back(n1);
        um[n1]++;
    }
    cin >> M;
    for (int i = 0; i < M; i++) {
        int n1;
        cin >> n1;
        X.push_back(n1);
    }

    sort(A.begin(), A.end());


    for (int i = 0; i < M; i++) {
        bool found = binarySearch(A, X[i], 0, A.size() - 1);
        if (found) {
            cout << um[X[i]] << " ";
        }
        else {
            cout << 0 << " ";
        }
    }

    return 0;
}
//0 1 2 3 4 
// mid = 2
// mid = 3