#include <iostream>
using namespace std;

using ld = long double;
using ll = long long;
ll power(ll a, ll b, ll m) {
    ll res = 1;
    a %= m;
    while (b > 0) {
        if (b % 2 == 1) res = (res * a) % m;
        a = (a * a) % m;
        b /= 2;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;
    const ll MOD = 1e9 + 7;
    while (n--) {
        ll a, b, c;
        cin >> a >> b >> c;
        // Step 1: Calculate E = b^c mod (MOD - 1)
        ll exp = power(b, c, 1e9+6);
        
        // Step 2: Calculate a^E mod MOD
        cout << power(a, exp, MOD) << "\n";
    }
    return 0;
}
