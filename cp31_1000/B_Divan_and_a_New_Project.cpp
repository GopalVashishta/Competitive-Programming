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
        vector<pair<ll, ll>> arr; 
        for(ll i=0; i<n; i++){
            ll x; cin >> x;
            arr.push_back({x, i});
        }
        // ARG: we place the boss house at 0, then insert the biggest at right, then next biggest at left, then again at right
        // we increment the coord of l & r each time we place a building
        sort(arr.rbegin(), arr.rend());// sort in descending order;

        vector<ll> ans(n+1, 0);
        
        ans[0] = 0;
        ll mins = 0;
        ll coord = 1;
        for(ll i=0; i<n; i++){
            ans[arr[i].second+1] = coord;
            mins += (2 * abs(coord) * arr[i].first);
            if(coord < 0)
                coord = abs(coord)+1;
            else 
                coord = -coord;
        }

        coutn(mins);
        for(const auto &x: ans) cout << x << ' ';
        cout << "\n";
    }
    return 0;
}