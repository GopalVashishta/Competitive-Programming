// C++ Competitive Programming Template
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


#if __cplusplus >= 201703L
    #include <numeric>
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif

template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

template<typename T>
T isqrt(T x) {
    T left = 0, right = x, ans = 0;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

ll modpow(ll a, ll b, ll m = 1000000007) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    const int MOD = 1e9 + 7;
    int n = s.length();

    for (char c : s) {
        if (c == 'm' || c == 'w') {
            cout << 0 << '\n';
            return 0;
        }
    }
    vector<ll> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i - 1];
        if (i >= 2 && ((s[i - 1] == 'u' && s[i - 2] == 'u') || (s[i - 1] == 'n' && s[i - 2] == 'n'))) {
            dp[i] = (dp[i] + dp[i - 2]) % MOD;
        }
    }
    cout << dp[n] << '\n';
    return 0;
}
