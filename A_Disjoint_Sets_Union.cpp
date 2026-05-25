#include<bits/stdc++.h>
using namespace std;

class dsu{
    public:
        vector<int> parent;
        dsu(int n){
            parent.resize(n+1);
            for(int i=0; i<n; i++) parent[i] = i;
        }
        int findp(int node){
            if(parent[node] == node) return node;
            return parent[node] = findp(parent[node]);
        }
        string get(int a, int b){
            return findp(a) == findp(b) ? "YES": "NO";
        }
        bool sunion(int a, int b){
            int ua = findp(a), ub =findp(b);
            if(ua == ub) return false;
            //if(size[ub] > size[ua]) swap(ua, ub);
            parent[ub] = ua;
            return true;
        }
};

int main(){
    int n, m; cin >> n >> m;
    dsu d(n);
    while(m--){
        string s; int a,b; cin >> s >> a >> b;
        if(s == "union"){
            d.sunion(a,b);
        }
        else cout << d.get(a,b) << "\n";
    }
    return 0;

}