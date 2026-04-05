#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solve(vector<long long>& a, long long c) {
    sort(a.begin(), a.end()); 
    int n = a.size();
    int min_coins = n;

    for (int k = 0; k <= n; ++k) {
        int coins = 0;
        long long mult = 1;
        for (int i = 0; i < n - k; ++i) {
            if (a[i] * mult > c) coins++;
            mult *= 2; 
        }
        for (int i = n - k; i < n; ++i) {
            if (a[i] > c) coins++;
        }

        min_coins = min(min_coins, coins);
    }

    return min_coins;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        long long c;
        cin >> n >> c;
        vector<long long> a(n);
        for (int i = 0; i < n; ++i) cin >> a[i];
        cout << solve(a, c) << endl;
    }
    return 0;
}
