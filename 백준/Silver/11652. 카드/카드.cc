#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;

int main() {
    ios::sync_with_stdio(false); // Using 'false' is more explicit.
    cin.tie(0);

    int N; // Number of elements
    cin >> N;

    map<ll, ll> freq; // To store frequencies of each number
    ll number;

    for (int i = 0; i < N; i++) {
        cin >> number;
        freq[number]++; // Increment frequency of each number directly without needing a vector
    }
    
    ll maxFrequency = 0;
    ll numberWithMaxFreq = 0;

    for (const auto& entry : freq) {
        if (entry.second > maxFrequency) {
            maxFrequency = entry.second;
            numberWithMaxFreq = entry.first;
        }
    }

    cout << numberWithMaxFreq << endl; // Print the number with the highest frequency
    return 0;
}
