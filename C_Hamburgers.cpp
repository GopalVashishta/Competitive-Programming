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
    int nb, ns, nc, pb, ps, pc;
    cin >> nb >> ns >> nc >> pb >> ps >> pc;
    long long rub;
    cin >> rub;
    long long l = 0, r = 1e12 + 100;
    array<int, 3> cnt{};
    for (char c : s) {
        if (c == 'B') {
            cnt[0]++;
        }
        else if (c == 'S') {
            cnt[1]++;
        }
        else {
            cnt[2]++;
        }
    }
    auto possible = [&] (long long mid) {
        long long reqb = max(0ll, mid * cnt[0] - nb);//already available so remove them 
        long long reqs = max(0ll, mid * cnt[1] - ns);
        long long reqc = max(0ll, mid * cnt[2] - nc);
        long long moneyReq = pb * reqb + ps * reqs + pc * reqc;
        return moneyReq <= rub;
    };
    while (l <= r) {
        long long mid = (l + r) / 2;

        if (possible(mid)) {
            l = mid + 1;
        }
        else {
            r = mid - 1;
        }
    }
    cout << l - 1 << '\n';//T T T T T F ... it calcualtes lb for this i.e last T
    return 0;
}
