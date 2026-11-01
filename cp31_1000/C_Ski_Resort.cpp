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
    int tc; cin >> tc;
    while(tc--){
        ll n, k, q; cins(n, k, q);
        vector<ll> arr(n);
        for(auto &x: arr){
            cin >> x;
            x = x<=q ? 1: 0; // if valid temp then 1 else 0
        }

        ll ans = 0, cnt = 0;
        for(const auto &x: arr){
            if(x == 1) cnt++;
            else{ // when reached 0 we can now count for this segment
                if(cnt>=k){ // if valid length, calculate for this segment
                    ll diff = cnt-k+1;
                    ans+= diff*(diff+1)/2;
                }
                cnt =0; // reset
            }
        }
        if(cnt>=k){ // if terminated at 1, 0 0 0 1 1 1 1
            ll diff = cnt-k+1;
            ans+= diff*(diff+1)/2;
        }
        coutn(ans);
    }
    return 0;
}