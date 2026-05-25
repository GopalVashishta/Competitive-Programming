#include<bits/stdc++.h>
using namespace std;

class dsu{
    public:
        vector<int> parent, mn, mx, size;

        dsu(int n){
            parent.resize(n+1); size.resize(n+1, 1);
            mn.resize(n+1); mx.resize(n+1);
            for(int i=0; i<=n; i++) {
                parent[i] = i; 
                mn[i] = i; 
                mx[i]=i;
            }
        }
        int findp(int node){
            if(parent[node] == node) return node;
            return parent[node] = findp(parent[node]);
        }
        void get(int a){
            int par = findp(a);
            cout << mn[par] << " " << mx[par] << " " << size[par] << "\n";
        }
        bool sunion(int a, int b){
            int ua = findp(a), ub =findp(b);
            if(ua == ub) return false;
            if(size[ub] > size[ua]) swap(ua, ub);
            parent[ub] = ua;
            size[ua] +=size[ub];
            mn[ua] = min(mn[ua], mn[ub]);
            mx[ua] = max(mx[ua], mx[ub]);
            return true;
        }
};

int main(){
    int n, m; cin >> n >> m;
    dsu d(n);
    while(m--){
        string s; cin >> s;
        if(s == "union"){
            int a, b; cin >> a >> b;
            d.sunion(a,b);
        }
        else {
            int a; cin >> a;
            d.get(a);
        }
    }
    return 0;

}