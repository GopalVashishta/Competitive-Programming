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


#if __cplusplus >= 201703L
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif


ll prefixs(int ind, vector<int> &fenwick) {
    ll sum = 0;
    while (ind > 0) {
        sum += fenwick[ind]; //global
        ind -= (ind & -ind);
    }
    return sum;
}
void update(int ind, int v, vector<int>& fenwick){
    int n = fenwick.size(); 
    while(ind <= n){  //can also remove'='
        fenwick[ind] += v;
        ind += (ind & -ind);
    }
}

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
    int t; 
    if(!(cin >> t)) return 0;
    while(t--) {
        int n; cin >> n;
        for(int i=1;i<=n;i++){
            if(i%2==1) cout << -1;
            else {
                if(i==n) cout << 2;
                else cout << 3;
            }
            if(i<n) cout << ' ';
        }
        couts("\n");
    }
    return 0;
}