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
        ll n; char c; string s; cins(n, c, s);
        ll ans = 0;
        ll first_gix = -1, gix = n;
        // ARG: find the dist to immediate right ix (with wrap around)
        
        for(ll i=0; i<n; i++){ // find the first occurence of g
            if(s[i] == 'g') {first_gix = i; break;}
        }

        for(ll i = n-1; i>=0; i--){
            if(s[i] == 'g'){ // retain the direct right index which has green
                gix = i;
            }
            else if(s[i] == c) { // if no green dirctly to right calc with the leftmost gix, else selc the direct right g ix
                ans = max(ans, ((gix == n)? (n - i) + first_gix: gix-i));
            }
        }
        coutn(ans);
    }
    return 0;
}