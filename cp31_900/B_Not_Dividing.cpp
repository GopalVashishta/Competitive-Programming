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

        for(auto &x: arr){ if(x==1) x++; } // get rid of 1s cuz 1 divides all (atmax n oprs)
        
        for(int i=0; i<n-1; i++){
            if(arr[i+1]%arr[i] ==  0){ // at max n-1 operations
                arr[i+1]++;
            }
        }

        for(const auto x: arr) cout << x << " ";
        cout << "\n";
    }
    return 0;
}