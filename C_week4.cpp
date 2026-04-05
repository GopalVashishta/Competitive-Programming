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
    int n;
    cin >> n;
    vector<int> a(n), dist(n, -1);
    vector<vector<int>> invg(n);

    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i - a[i] >= 0) invg[i - a[i]].push_back(i);
        if (i + a[i] < n) invg[i + a[i]].push_back(i);
    }

    queue<int> q;
    for (int i = 0; i < n; ++i) {
        int to1 = i - a[i];
        int to2 = i + a[i];
        if ((to1 >= 0 && (a[to1] % 2 != a[i] % 2)) || 
            (to2 < n && (a[to2] % 2 != a[i] % 2))) {
            dist[i] = 1;
            q.push(i);
        }
    }
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (int v : invg[u]) {
            if (dist[v] == -1 && (a[v] % 2 == a[u] % 2)) {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }

    for (int i = 0; i < n; ++i)  couts(dist[i]);
    return 0;
}