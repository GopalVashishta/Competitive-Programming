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
        int n, x; cins(n, x);
        vector<ll> arr(n); cinv(arr);
        // now |v-ai| <= x, (|y| <=x -> -x <= y <= y)
        // we can say ai-x <= v <= ai+x, we get ranges for each index
        // then we do LC(i got in scaler OA) merge Intervals on it, just dont do sorting cuz we need order

        vector<pair<ll, ll>> segments(n);
        for(int i=0; i<n; i++){ // create interval segments
            segments[i] = {arr[i]-x, arr[i]+x};
        }

        ll ans = 0;
        ll l = segments[0].first;
        ll r = segments[0].second;

        for(int i = 1; i<n; i++) {

            l = max(l, segments[i].first);
            r = min(r, segments[i].second);

            if(l > r) { // if overlapping
                ans++;
                l = segments[i].first;
                r = segments[i].second;
            }
        }
        coutn(ans);


        /* // i tried with LC solution, worked for a few cases
        vector<vector<int>> interval;
        for(const auto &val: arr){
            interval.push_back({val-x, val+x}); // convert to interval
        }
        vector<vector<int>> final_interval;
        for(const auto &x: interval){
            if(final_interval.empty() || final_interval.back()[1] < x[0]) final_interval.push_back(x);
            else {
                final_interval.back()[0] = min(final_interval.back()[0], x[0]);
                final_interval.back()[1] = max(final_interval.back()[1], x[1]);
            }
        }
        coutn(final_interval.size()-1);
        */
    }
    return 0;
}