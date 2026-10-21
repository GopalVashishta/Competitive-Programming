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
        int n; cin >> n;
        vector<int> arr(n); cinv(arr);
        if(n&1){ // Preferrably look at even soln cuz 0-> (n-1) are even
            coutn(4); // only need 4 operations do 1->(n-1) [or 0->(n-2)] 2 times & (n-1)->n [or (n-2)->(n-1)] also 2 times
            cout << 1 << " " << n-1 <<"\n"; 
            cout << 1 << " " << n-1 <<"\n";
            cout << n-1 << " " << n << "\n"; 
            cout << n-1 << " " << n << "\n";
        }
        else{ // if n is even we can just take l=0, r=n-1(for output l=1, r=n), the 2nd time whole arr = 0
            coutn(2);
            cout << 1 << " " << n <<"\n"; 
            cout << 1 << " " << n <<"\n";
        }
    }
    return 0;
}