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
        // if we start l->r, any change we make later part of array will cause changes to be made to the left side of that ix
        // the code for above will be ambigious & would required retracing the previous elements bumping TC

        // that is why we do r->l and do it so if anything is not possible it'll be direct
        ll ans =0; 
        for(int i=n-2; i>=0; i--){
            while(arr[i] >= arr[i+1]){ // while cur ele >= next ele
                ans++;
                arr[i]/=2;
                if(!arr[i]) break; // if ele is 0 stop
            }
            if(arr[i]==0 && arr[i+1] ==0){// if both 0 cant do anything array not stricly inc.
                ans = -1; break;
            }
        }
        coutn(ans);
    }
    
    return 0;
}