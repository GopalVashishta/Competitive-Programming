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

int main() {
    fast;
    int t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> S(n), T(n);
        for (int i = 0; i < n; i++) cin >> S[i];
        for (int i = 0; i < n; i++) cin >> T[i];

        map<ll, ll> cs, ct;

        for (ll x : S) cs[x % k]++;
        for (ll x : T) ct[x % k]++;

        bool ok = true;
        set<ll> residues; 
        for (auto &p : cs) residues.insert(p.first);
        for (auto &p : ct) residues.insert(p.first);

        for (ll r : residues) {
            ll p = (k - r) % k;
            if (r > p) continue;

            ll sumS = cs[r] + (r != p ? cs[p] : 0);
            ll sumT = ct[r] + (r != p ? ct[p] : 0);

            if (sumS != sumT) {
                ok = false;
                break;
            }
        }

        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}