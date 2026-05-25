// C++ Competitive Programming Template
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (auto &x : arr) cin >> x;
    sort(arr.begin(), arr.end());

    int x;
    if (k == 0) {
        // Need x < arr[0] and x >= 1
        if (arr[0] > 1)
            x = arr[0] - 1;
        else
            x = -1;
    } else if (k <= n) {
        // x = arr[k-1], but must check arr[k-1] < arr[k] (if k < n)
        if (k == n || arr[k - 1] < arr[k])
            x = arr[k - 1];
        else
            x = -1;
    } else {
        x = -1;
    }
    cout << x << "\n";
    return 0;
}
