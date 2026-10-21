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
        int a, b, n; cins(a, b, n);
        vector<int> arr(n); 
        // contribution of a tool will be min(xi, a-c); and then sum all these, c == 1
        // when we reach 1 we change val using any tool
        ll sum = b; // initial timer val
        for(auto &x: arr){
            cin >> x;
            sum += min(x, a-1);
        }
        coutn(sum);

    }
    return 0;
}