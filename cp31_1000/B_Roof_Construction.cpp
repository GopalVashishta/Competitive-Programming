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
        // if N is the highest num in the permutation we cant remove its msb, if 8 then cant remove(1) from: 1 0 0 0
        // however we can increase this value => x >= 2^msb
        // we try to make x == 2^msb
        
        
        ll n; cin >> n;
        n--; // as per permutation(with 0)
        ll msb = log2(n); // log2 give the hightest bit if n=7, msb=3;
        vector<ll> ans;

        ll num = pow(2, msb) -1;
        while(num >= 0) { // 2^msb -1 -> 0
            ans.push_back(num);
            num--;
        }

        num = pow(2, msb);
        while(num<=n) { // 2^msb -> N-1
            ans.push_back(num);
            num++;
        }
        
        for(const auto &x: ans)
            cout << x << " ";
        cout << "\n";
    }
    return 0;
}