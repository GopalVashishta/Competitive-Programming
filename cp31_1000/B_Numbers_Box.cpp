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

ll next_prime(ll n){
    for(ll i=n;; i++) {
        bool isPrime = true;
        for(ll j=2; j*j <= i; j++) {
            if(i%j == 0) {
                isPrime = false;
                break;
            }
        }
        if(isPrime) return i;
    }
}

int main() {
    fast;
    ll tc; cin >> tc;

    while(tc--){ 
        ll n, m; cin >> n >> m;
        // IMP: if there 2 non adjacnet negs,
        // we can keep on flipping the adjs starting from neg ix & bring neg to the other neg & do flip
        ll abssum = 0, negcnt = 0;
        ll mn = 1e9; // NIMP: will handle the 0 val issue no need for zcnt (below)

        vector<vector<ll>> nums(n, vector<ll>(m, 0));
        for(auto &x: nums){
            for(auto &y: x) { 
                cin >> y;
                mn = min(mn, abs(y));
                abssum+=abs(y);
                if(y<0) negcnt++;
            }
        }
        if(!(negcnt&1)) { // covered after(code change)or atleast 1 occur of 0 exist(we can again bring neg to 0 & flip)
            coutn(abssum); // if even pairs we can flip all & get maxAbsSum(grid)
            continue;
        }
        coutn(abssum-2*mn); // make the smallest element neg
        // 2*mn: remove the already added sum from abssum, then dec the sum actually
    }
    return 0;
}