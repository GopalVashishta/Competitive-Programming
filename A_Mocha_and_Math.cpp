#include <iostream>
#include <vector>
#include <numeric> // For std::accumulate, although a simple loop is fine too
using namespace std;
int main() {
    std::ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        int result_and = -1; // Initialize with a value that ensures first element correctly initializes AND
                             // Or, simply read the first element into result_and and loop from the second
        cin >> a[0];
        result_and = a[0];
        for (int i = 1; i < n; ++i) {
            cin >> a[i];
            result_and &= a[i];
        }
        cout << result_and << "\n";
    }
    return 0;
}
