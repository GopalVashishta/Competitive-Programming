#include<bits/stdc++.h>
using namespace std;

void dfs(int src, vector<int> adj[],vector<bool> &vis){
    vis[src] = true;
    for(auto a: adj[src]){
        if(!vis[a]) dfs(a,adj,vis);
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; 
    cin >> n>>m;
    vector<int> adj[n+1];
    vector<bool> vis(n+1);
    vector<int> comp;
    for(int i =0; i<m; i++){
        int a,b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int cnt = 0;
    for(int i=1; i<=n; i++){
        if(!vis[i]){
            cnt++;
            dfs(i, adj, vis);
            comp.push_back(i);
        }
    }
    cout<<cnt-1<<"\n";
    for(int i=1; i<comp.size(); i++){
        cout<<comp[i-1]<<" "<<comp[i]<<"\n";
    }
    return 0;
}