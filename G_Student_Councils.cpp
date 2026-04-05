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

bool canFormCouncils(ll m, ll k, const vector<int>& a) {
    long long totalStud = 0;
    for (auto &x:a) {
        totalStud += min(x*1LL, m);
    }
    return totalStud >= m * k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll k,n; cin>>k>>n;
    ll tot =0;
    vector<int> arr(n);
    for(auto& x: arr) {  cin>>x; tot+=x;}
    ll l =1.0, r = tot/k;//r is the Upper bound(total students divided into k councils)
    ll ans =0;
    while(l<=r){
        ll mid = l+ (r-l)/2LL;
        if (canFormCouncils(mid, k, arr)) {
            ans = mid;  // If possible, we can form at least `mid` councils
            l = mid + 1; // Try for more councils
        } else {
            r = mid - 1; // Try fewer councils
        }
    }
    cout<<ans;
    return 0;

}
