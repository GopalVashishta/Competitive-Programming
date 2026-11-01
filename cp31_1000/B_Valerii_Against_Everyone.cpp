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
        ll n; cin >> n;
        vector<ll> arr(n); // no need to do 2^val cuz if 10^9 then 2^(10^9) is TOOOOOBIG NIGG.

        // ARG: if there are duplicates in arr the ans is YES , else NO
        // cuz 1 2 4 16 15 2, here 2 happens 2 times so we can pick 2 & 2 get YES
        unordered_map<ll, ll> mp;
        for(auto &x: arr){
            cin >> x;
            mp[x]++;
        }
        coutn((mp.size() <n) ? "YES": "NO");

    }
    return 0;
}