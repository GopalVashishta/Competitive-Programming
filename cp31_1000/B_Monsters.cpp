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


bool cmp(pair<ll, ll> &a, pair<ll, ll> &b){
    if(a.first != b.first) return a.first>b.first;
    return a.second < b.second;
}
int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n, k; cins(n, k);
        vector<pair<ll, ll>> arr;
        for(int i=0; i<n; i++){
            int x; cin >> x;
            x = (x%k == 0) ? k: x%k; // do non fatal attack, after doing these we have fatal attacks left only so 1 hit everyone
            arr.push_back({x, i+1});
        } // after these all the monsters will be 1 hit rem
        sort(arr.begin(), arr.end(), cmp); // sort these based on highest val(if same smallest ix)
        for(const auto &x: arr){ // print these cuz thats the order in which monsters die
            couts(x.second);
        }
        cout << "\n";

    }
    return 0;
}