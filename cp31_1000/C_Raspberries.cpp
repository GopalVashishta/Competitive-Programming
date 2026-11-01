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
        int n,k; cins(n, k);
        vector<ll> arr(n); 

        ll ans = INT_MAX;
        ll evencnt = 0; 
        for(auto &x: arr){
            cin >> x;
            if(!(x&1)) evencnt++;
            if(x%k == 0) ans = 0; // array already has a multiple of k, no need of Opr
            ans = min(ans, k-x%k);
        }
        if(k == 4){ // edge case handling
            if(evencnt >= 2) ans = min(ans, 0LL); // 2evens make multiple of 4
            else if(evencnt == 1) ans = min(ans, 1LL); // rest of all no. will be odd so we just have to +1
            else ans= min(ans, 2LL);
        }
        coutn(ans);

        // cant do like this, cuz test case 5
        // we can see there are k = 4, and 1, 1 in array so we can do 2 oprs, 
        // however i try to make it 4 so it'll take 3 ops, so this Approach WRONG

        /* // FAILED APPROACH: WE HAVE TO HANDLE THE ABOVE CASE
        int ans = 100;
        for(const auto &x: arr){ 
            ans = min(ans,k- x%k); 
        }
        coutn(ans);
        */
    }
    return 0;
}