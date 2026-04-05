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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cins(n,m,k);
    vector<vector<pair<ll, ll>>> adj(n + 1);
    for (int i = 0; i < m; i++) {
        ll a, b;
        ll c;
        cin >> a >> b >> c;
        adj[a].push_back({c, b});
    }

    vector<ll> count(n + 1, 0);
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
    pq.push({0, 1});
    vector<ll> res;
    while (!pq.empty()) {
        auto [cost, u] = pq.top();
        pq.pop();
        count[u]++;
        if (u == n) {
            res.push_back(cost);
            int rs = res.size();
            if (rs == k) break;
        }
        if (count[u] > k) continue;
        for (auto [w, v] : adj[u]) {
            pq.push({cost + w, v});
        }
    }

    for (ll c : res) couts(c);
    return 0;
}