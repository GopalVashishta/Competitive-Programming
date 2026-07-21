#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
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

class DSU {
    vector<int> parent, size;
public:
    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        iota(parent.begin(), parent.end(), 0);
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
    fast;
    int tc; cin >> tc;
    while(tc--){
        ll n, x, y; cins(n,x ,y);
        vector<ll> arr(n+1); for(int i=1; i<=n; i++) cin >> arr[i];
        DSU ds(n); // if we can swap(a,b) & swap(b,c) we can Ultimately swap(a,c) & so On
        for(int i=1; i<=n; i++){
            if(i+x<=n) ds.Unionbysize(i, i+x);
            if(i+y<=n) ds.Unionbysize(i, i+y);
        }
        string ans = "YES";
        for(int i=1; i<=n; i++){
            if(ds.findparent(i) != ds.findparent(arr[i])){
                ans = "NO"; break;
            }
        }
        cout << ans << "\n";

    }
    return 0;
}

