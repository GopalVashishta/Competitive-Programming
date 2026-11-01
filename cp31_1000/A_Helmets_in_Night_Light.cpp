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
        int n, p; cins(n, p);
        vector<pair<int, int>> arr(n); // cost, no. of ppl can share with : cuz easier to sort
        for(auto &[x, y]: arr){ // take cost first
            cin >> y;
        }
        for(auto &[x, y]: arr){
            cin >> x; // then no. of pplt
        }

        sort(arr.begin(), arr.end());

        ll mincost = p; // pak chanek have to share to aleast 1 person
        ll already_shared = 1; // ^ 

        for(auto [cost, can_share]: arr){

            if(cost > p) break; // we rather have pak chanek tell people cuz less cost

            if(already_shared + can_share > n){ // if less people than can share we share to all remaining
                mincost += (n-already_shared)*cost;
                already_shared = n; // shared to all  & stop now
                break;
            }
            else {
                mincost += can_share*cost; // share to all no. of ppl we can
                already_shared+=can_share; // add cnt to shared ppl
            }

        }
        
        mincost += (n - already_shared) * p; // pakchanek shares to rest
        coutn(mincost);
    }
    return 0;
}