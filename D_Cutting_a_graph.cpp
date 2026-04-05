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
class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for (int i = 1; i <= n; ++i) parent[i] = i;
    }
    int findparent(int n) {
        if (n == parent[n]) return n;
        return parent[n] = findparent(parent[n]);
    }
    void Unionbysize(int a, int b) {
        int pa = findparent(a), pb = findparent(b);
        if (pa == pb) return;
        if (size[pa] < size[pb]) swap(pa, pb);
        parent[pb] = pa;
        size[pa] += size[pb];
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, k;
    cins(n, m, k);

    vector<pair<int, int>> edges(m);
    map<pair<int, int>, int> edge_idx;
    for (int i = 0; i < m; ++i) {
        int u, v;
        cins(u, v);
        if (u > v) swap(u, v);
        edges[i] = {u, v};
        edge_idx[{u, v}] = i;
    }

    vector<tuple<string, int, int>> ops(k);
    set<pair<int, int>> to_cut;
    for (int i = 0; i < k; ++i) {
        string op;
        int u, v;
        cin >> op >> u >> v;
        if (u > v) swap(u, v);
        ops[i] = {op, u, v};
        if (op == "cut") to_cut.insert({u, v});
    }

    DSU dsu(n);
    // Add edges not cut
    for (auto& e : edges) {
        if (to_cut.count(e) == 0) {
            dsu.Unionbysize(e.first, e.second);
        }
    }

    vector<string> res;
    // Process operations in reverse
    for (int i = k - 1; i >= 0; --i) {
        auto [op, u, v] = ops[i];
        if (op == "ask") {
            if (dsu.findparent(u) == dsu.findparent(v)) res.push_back("YES");
            else res.push_back("NO");
        } else if (op == "cut") {
            dsu.Unionbysize(u, v);
        }
    }
    reverse(res.begin(), res.end());
    for (auto& ans : res) cout << ans << '\n';
    return 0;
}