/*This is quesiton is Forest Queries of CSES*/
// C++ Competitive Programming Template
#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


#if __cplusplus >= 201703L
    #include <numeric>
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif

template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

template<typename T>
T isqrt(T x) {
    T left = 0, right = x, ans = 0;
    while (left <= right) {
        T mid = left + (right - left) / 2;
        if (mid * mid <= x) {
            ans = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return ans;
}

ll modpow(ll a, ll b, ll m = 1000000007) {
    ll res = 1;
    a %= m;
    while (b) {
        if (b & 1) res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}
/*This is quesiton is Forest Queries of CSES*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,q; 
    cin>>n>>q;
    vector<string> gp(n);
    for(int i = 0; i < n; i++) {
        cin >> gp[i];
    }
    vector<vector<int>> preSum(n+1, vector<int>(n+1));
    for(int i=1; i<=n; i++){
        for(int j=1; j<=n; j++){
            preSum[i][j] = preSum[i-1][j] + preSum[i][j-1] - preSum[i-1][j-1] + (gp[i-1][j-1] == '*');
        }
    }
    while(q--){
        int y1,x1,y2,x2;
        cin>>y1>>x1>>y2>>x2;
        int ans = preSum[y2][x2] - preSum[y1-1][x2] - preSum[y2][x1-1] + preSum[y1-1][x1-1];
        cout<<ans<<"\n";
    }
    return 0;
}
