#include <bits/stdc++.h>
using namespace std;

int search(int tar, const vector<int> &arr) {
    int n = arr.size();
    int low = 0, high = (n - 1) / 2;  // searching in half indices
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int idx = mid * 2;  // map to even index

        if (arr[idx] <= tar) {
            ans = idx;  // possible answer
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

#define cinv(v) for (auto &x : v) { cin >> x; }

int main() {
    int n, tar;
    cin >> n >> tar;
    vector<int> arr(n);
    cinv(arr);

    int ans = search(tar, arr);

    if (ans == -1) {
        cout << -1 << "\n";  // no element <= tar found at even indices
        return 0;
    }

    if (arr[ans] == tar) {
        cout << ans << "\n";
        return 0;
    }

    // If exact target not found, output index of greatest even-indexed element <= tar
    cout << ans << "\n";
    return 0;
}
