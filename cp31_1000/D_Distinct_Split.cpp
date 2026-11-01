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

int main() {
    fast;
    ll tc; cin >> tc;
    while(tc--){
        ll n; string s;
        cins(n, s);

        unordered_set<char> pref, suf;
        vector<ll> pref_distinct_cnt(n), suff_distinct_cnt(n, 0);

        for(ll i=0; i<n; i++){
            pref.insert(s[i]);
            pref_distinct_cnt[i] = pref.size();

            suff_distinct_cnt[n-i-1] = suf.size();// dont include the currt ele either in suff or Pref cuz we cant count an elemen in both segments
            suf.insert(s[n-i-1]);
        }

        ll mx = 0;
        for(ll i=0; i<n; i++){
            mx = max(mx, pref_distinct_cnt[i]+suff_distinct_cnt[i]);
        }
        
        coutn(mx);
    }
    return 0;
}