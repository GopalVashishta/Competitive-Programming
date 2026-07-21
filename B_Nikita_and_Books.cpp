#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <cmath>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)


using ld = long double;
using ll = long long;

int main() {
    fast;
    int tc; cin >> tc;
    while(tc--){
        int n; cin >> n;
        vector<int> arr(n);
        for(auto &x: arr) cin >> x;
        string ans = "YES";
        ll sum = 0;
        for(int i=0; i<n; i++){
            sum+=arr[i];
            int val = i+1;
            ll minsum = (val*(val+1))/2;
            if(sum < minsum){
                ans = "NO"; break;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}