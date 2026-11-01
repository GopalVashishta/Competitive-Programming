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

pair<ll, ll> f_and_s_lowest(vector<ll> &arr){
    pair<ll, ll> ans = {INT_MAX, INT_MAX};
    for(const auto &x:arr){
        if(x < ans.first) { ans.second = ans.first; ans.first = x; }
        else if( x < ans.second) ans.second = x;
    }
    return ans;
}

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        ll n; cin >> n;
        vector<ll> secnd_ele; // store the 2nd colmn for n-1 rows
        ll lowest_first_min = INT_MAX; // find lowest from 1st col

        /* Instead of Sorting we can also write a func to find 1st and 2nd smallest in a vector */
        for(int i=0; i<n; i++) {
            ll m; cin >> m;
            vector<ll> tp(m);
            cinv(tp);
            //sort(tp.begin(), tp.end());
            pair<ll, ll> pr = f_and_s_lowest(tp);
            secnd_ele.push_back(pr.second); // 2nd ele for each row (2nd col ele)
            lowest_first_min = min(lowest_first_min, pr.first); // retain the lowest from 1st colmn for all rows
        }
        //sort(secnd_ele.begin(), secnd_ele.end()); // sort these eles
        pair<ll, ll> pr = f_and_s_lowest(secnd_ele);

        ll sum_of_2nd_ele = accumulate(secnd_ele.begin(), secnd_ele.end(), 0LL); // sum for beauty
        ll lowest_2nd_min = pr.first; // we dont need this ele in sum
        ll ans = lowest_first_min + sum_of_2nd_ele - lowest_2nd_min; // replace with lowest ele from 1st colmn
        coutn(ans);
    }
    return 0;
}