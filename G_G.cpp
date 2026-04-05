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

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, m; cins(n,m);

    vector<vector<ll>> graph(n + 1);
    vector<ll> indegree(n + 1, 0);
    for (ll i = 0; i < m; ++i) {
        ll a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        indegree[b]++;
    }
    const ll INF = -1e9;
    queue<ll> q;
    for (ll i = 1; i <= n; ++i)
        if (indegree[i] == 0)
            q.push(i);

    vector<ll> topo;
    while (!q.empty()) {
        ll u = q.front(); q.pop();
        topo.push_back(u);
        for (ll v : graph[u]) {
            if (--indegree[v] == 0)
                q.push(v);
        }
    }

    vector<ll> dist(n + 1, INF);
    vector<ll> prev(n + 1, -1);
    dist[1] = 1;

    for (ll u : topo) {
        for (ll v : graph[u]) {
            if (dist[u] + 1 > dist[v]) {
                dist[v] = dist[u] + 1;
                prev[v] = u;
            }
        }
    }
    if (dist[n] == INF) {
        coutn("IMPOSSIBLE");
        return 0;
    }
    vector<ll> path;
    for (ll cur = n; cur != -1; cur = prev[cur])
        path.push_back(cur);
    reverse(path.begin(), path.end());
    coutn(path.size());
    for (ll x : path)
        couts(x);
    return 0;
}