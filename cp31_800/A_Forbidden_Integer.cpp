#include <iostream>
#include <vector>

using namespace std;

int main() {
    // Optimize standard I/O operations execution speed
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int tc; 
    cin >> tc;
    while (tc--) {
        int n, k, x; 
        cin >> n >> k >> x;
        
        // Case 1: 1 is not forbidden, always use 1s
        if (x != 1) {
            cout << "YES\n" << n << "\n";
            for (int i = 0; i < n; i++) {
                cout << 1 << (i == n - 1 ? "" : " ");
            }
            cout << "\n";
            continue;
        }

        // Case 2: 1 is forbidden and k is 1, impossible to form any positive number
        if (k == 1) {
            cout << "NO\n";
            continue;
        }

        // Case 3: 1 is forbidden but n is even, use 2s
        if (n % 2 == 0) {
            cout << "YES\n" << n / 2 << "\n";
            for (int i = 0; i < n / 2; i++) {
                cout << 2 << (i == n / 2 - 1 ? "" : " ");
            }
            cout << "\n";
            continue;
        } 
        
        // Case 4: 1 is forbidden, n is odd, and k >= 3. 
        // We must ensure n >= 3 to cleanly take away a '3' element.
        if (k >= 3 && n >= 3) {
            cout << "YES\n" << (n - 3) / 2 + 1 << "\n";
            cout << 3;
            for (int i = 0; i < (n - 3) / 2; i++) {
                cout << " " << 2;
            }
            cout << "\n";
            continue;
        }

        // Case 5: 1 is forbidden, n is odd, but k < 3 or n < 3 (e.g., n = 1)
        cout << "NO\n";
    }
    return 0;
}