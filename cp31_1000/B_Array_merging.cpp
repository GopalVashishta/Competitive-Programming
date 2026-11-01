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
        ll n; cin >> n;
        // ARG: the ans is max(freqA[i]+freqB[i], ans), the longest subarry ele from a & b and their sum is ans
        // the hashmap approach will fail at cuz it'll not consider subarray from both a & b, it'll just consider freq
        vector<ll> a(n), b(n);
        cinv(a); cinv(b);
        
        vector<ll> longest_sub_a(2*n+1, 0), longest_sub_b(2*n+1, 0);// the val of a/b[i] is <= 2*n
        
        ll cnt = 1;
        for(ll i=1; i<n; i++){ // find the longest subarray, for a
            if(a[i] == a[i-1]) cnt++;
            else {
                longest_sub_a[a[i-1]] = max(longest_sub_a[a[i-1]], cnt);
                cnt=1;
            }
        }
        longest_sub_a[a[n-1]] = max(longest_sub_a[a[n-1]], cnt);

        cnt = 1;
        for(ll i=1; i<n; i++){ // find the longest subarray, for b
            if(b[i] == b[i-1]) cnt++;
            else {
                longest_sub_b[b[i-1]] = max(longest_sub_b[b[i-1]], cnt);
                cnt=1;
            }
        }
        longest_sub_b[b[n-1]] = max(longest_sub_b[b[n-1]], cnt);

        ll max_freq = -1;
        for(ll i = 0; i<=2*n; i++){
            max_freq = max(max_freq, longest_sub_a[i]+longest_sub_b[i]);
        }
        coutn(max_freq);
    }
    return 0;
}