#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)
template<typename... T> void cins(T&... args) { ((cin >> args), ...);}

#define cinv(v) for(auto &x: v){cin>>x;}

using ld = long double;
using ll = long long;

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll n, m, i,j; cins(n, m, i, j);
        // the ans can always be diagonals: (1,1) && (n, m) OR (n,1) && (1,m) cuz farthest
        cout << "1 1 " << n << " " << m << "\n";
    }
    return 0;
}