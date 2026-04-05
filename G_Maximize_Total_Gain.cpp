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
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutnl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


#if __cplusplus >= 201703L

    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif


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

ll fastexp(ll a, ll b, ll m = 1000000007) {
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

    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin >> a[i][j];

    // DP for Iahub: from (0,0) to (i,j)
    vector<vector<ll>> dp1(n, vector<ll>(m, 0));
    dp1[0][0] = a[0][0];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++) {
            if(i > 0) dp1[i][j] = max(dp1[i][j], dp1[i-1][j] + a[i][j]);
            if(j > 0) dp1[i][j] = max(dp1[i][j], dp1[i][j-1] + a[i][j]);
        }

    // DP for Iahub: from (i,j) to (n-1,m-1)
    vector<vector<ll>> dp2(n, vector<ll>(m, 0));
    dp2[n-1][m-1] = a[n-1][m-1];
    for(int i=n-1; i>=0; i--)
        for(int j=m-1; j>=0; j--) {
            if(i < n-1) dp2[i][j] = max(dp2[i][j], dp2[i+1][j] + a[i][j]);
            if(j < m-1) dp2[i][j] = max(dp2[i][j], dp2[i][j+1] + a[i][j]);
        }

    // DP for Iahubina: from (n-1,0) to (i,j)
    vector<vector<ll>> dp3(n, vector<ll>(m, 0));
    dp3[n-1][0] = a[n-1][0];
    for(int i=n-1; i>=0; i--)
        for(int j=0; j<m; j++) {
            if(i < n-1) dp3[i][j] = max(dp3[i][j], dp3[i+1][j] + a[i][j]);
            if(j > 0) dp3[i][j] = max(dp3[i][j], dp3[i][j-1] + a[i][j]);
        }

    // DP for Iahubina: from (i,j) to (0,m-1)
    vector<vector<ll>> dp4(n, vector<ll>(m, 0));
    dp4[0][m-1] = a[0][m-1];
    for(int i=0; i<n; i++)
        for(int j=m-1; j>=0; j--) {
            if(i > 0) dp4[i][j] = max(dp4[i][j], dp4[i-1][j] + a[i][j]);
            if(j < m-1) dp4[i][j] = max(dp4[i][j], dp4[i][j+1] + a[i][j]);
        }

    ll ans = 0;
    // Try all meeting points except borders
    for(int i=1; i<n-1; i++) {
        for(int j=1; j<m-1; j++) {
            // Two possible ways to avoid crossing at the meeting point
            ll way1 = dp1[i-1][j] + dp2[i+1][j] + dp3[i][j-1] + dp4[i][j+1];
            ll way2 = dp1[i][j-1] + dp2[i][j+1] + dp3[i+1][j] + dp4[i-1][j];
            ans = max(ans, max(way1, way2));
        }
    }
    coutn(ans);
    return 0;
}