#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <unordered_map>
typedef long long ll;
using namespace std;

int N, M;

unordered_map<int, int>um;

int binarySearch(vector<int>& A, int x, int left, int right) {
    if (left > right) {
        return false;
    }

    int mid = left + (right - left) / 2;

    if (A[mid] == x) {
        return mid;
    }
    else if (A[mid] > x) {
        return binarySearch(A, x, left, mid - 1);
    }
    else {
        return binarySearch(A, x, mid + 1, right);
    }
}

int main() {
    
    cin >> N;
    vector<int> v;
    vector<int> s;
    for (int i = 0; i < N; i++) {
        int n1;
        cin >> n1;
        v.push_back(n1);
        s.push_back(n1);
    }

    sort(v.begin(), v.end());

    v.erase(unique(v.begin(), v.end()),v.end());

    for (int i = 0; i < N;i++) {
        cout << binarySearch(v, s[i], 0, v.size()-1) << " ";
    }

    return 0;
}
//0 1 2 3 4 
// mid = 2
// mid = 3