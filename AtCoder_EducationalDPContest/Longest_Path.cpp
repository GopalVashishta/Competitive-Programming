#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;

int dfs(int node, vector<int> &dp, const vector<vector<int>>& adj){
    if(adj[node].size() == 0) return dp[node]=0;
    if(dp[node] != -1) return dp[node];

    int mx = 0;
    for(auto ngh: adj[node]){
        mx = max(mx, 1+dfs(ngh, dp ,adj));
    }
    return dp[node] = mx;
}
int main() {
    fast;
    int n, m; cins(n, m);
    // we can use DFS+Memoization(if already traversed on that node just use the DP value)
    // OR We can use TopoSort to start with the node which has outDegree ==0
    vector<vector<int>> adj(n + 1);
    vector<int> indg(n+1, 0);
    vector<int> dp(n+1, 0);
    for(int i=0; i<m; i++){
        int u,v; cins(u, v);
        adj[u].push_back(v);
        indg[v]++;
    }
    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (!indg[i]) { q.push(i); }
    }

    while (!q.empty()) {
        int u = q.front(); q.pop();

        for (int v : adj[u]) {
            // Relax the edge to maximize path length to v
            if (dp[u] + 1 > dp[v]) {
                dp[v] = dp[u] + 1;
            }

            indg[v]--;
            if (!indg[v]) { q.push(v); }
        }
    }

    // The answer is the maximum path found anywhere across the entire DP table
    int mx = 0;
    for (int i = 1; i <= n; ++i) {
        mx = max(mx, dp[i]);
    }
    
    /* 
    // dfs approach
    int mx = 0;
    for(int i=1; i<=n; i++){
        mx = max(mx,dfs(i, dp, adj));
    }
    */
    coutn(mx);
    return 0;
}