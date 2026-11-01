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
        vector<ll> arr(n); cinv(arr);
        // the eq can be written as:  j-i  != a[j] - a[i];
        // The diff j-i will always inc as indecies inc;
        // so what we do is reverse sort the array to make the a[j]-a[i] < 0
        sort(arr.rbegin(), arr.rend());
        for(const auto &x: arr) cout << x << " ";
        cout << "\n";
    }
    return 0;
}