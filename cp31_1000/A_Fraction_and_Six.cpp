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
        ll n,m; cins(n, m);
        string p,q; cins(p, q);

        unordered_map<char, ll> mp;
        for(const auto &c: q){
            mp[c]++;
        }

        unordered_map<char, ll> rem;
        for(const auto &c: p){
            if(mp[c]>0){
                mp[c]--; 
            }
            else rem[c]++;
        }
        
        bool check  = (rem.size() == 3 && rem['s'] == 1 && rem['i'] == 1 && rem['x'] == 1);

        for (auto &[c, cnt]: mp){ // if something is rem in denominator its false
            if(cnt > 0){
                check = false; break;
            }
        }

        // if >3 uniq chars, or >1 occur of six or No occur of any char of six ans is NO
        coutn((check)?"YES":"NO");
    }
    return 0;
}