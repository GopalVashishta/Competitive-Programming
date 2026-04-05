#include<iostream>
#include<vector>
#include<set>
#include<map>  
#include<unordered_map>
#include<unordered_set>
#include<queue>
#include<stack>
#include<algorithm>
#include<functional>
#include<utility>
#include<iterator>
#include<cstring>
#include<string.h>
#include<cmath>
#include<math.h>
using namespace std;

#define PI 3.14159
#define mod 1000000007
using ld = long double;
using ll = long long;


template<typename T>
T gcd(T a, T b) {
    while (b) { T t = b; b = a % b; a = t; }
    return a;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tc; cin>>tc;
    while(tc--){
        ll a, b; cin>>a>>b;
        ll ans = 1;
        while (b) {
        if (b & 1)
            ans = (ans * a) % mod;
        a = (a * a) % mod;
        b >>= 1;
    }
        cout << ans << endl;
    }
}

