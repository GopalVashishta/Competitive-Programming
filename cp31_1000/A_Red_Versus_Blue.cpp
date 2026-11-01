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
        ll n, r, b; cins(n, r, b);
        // ARG: separate each region with B cuz b<r & if b close to r then brbrb to minimum
        // so if b separates we have b+1 regions r b r, here b creates 2 regions
        
        string ans = "";
        ll len_of_rs = r/(b+1); // divide it into b+1 regions
        ll extra_rds = r%(b+1); // if not completely div y b+1 then some will remain

        string rs_in_single_reg = "";
        for(int i=0; i<len_of_rs; i++) rs_in_single_reg+='R';

        for(int times = 1; times<=b+1; times++){
            ans+=rs_in_single_reg;
            if(extra_rds > 0){
                ans+='R'; //add 1 from extra red to each region region 
                extra_rds--;
            }
            if(times != b+1)
                ans+='B'; // add one b to separate regions
        }
        coutn(ans);
    }
    return 0;
}