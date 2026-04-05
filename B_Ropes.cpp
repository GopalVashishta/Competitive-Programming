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

bool isPossible(vector<int> &arr, int k, double len){
    int cnt = 0;
    for(int rope: arr){
        cnt += (int) rope / len;
    }
    return cnt >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cin>>n>>k;
    vector<int> arr(n);
    double high = INT_MIN;
    for(auto &x: arr) {cin>>x; high = max(high,(double)x);}
    double ans = 0.0;
    double low = 0.0;
    for(int i=0; i<100; i++){
        double mid = (low+high)/2.0;
        if(isPossible(arr, k , mid)){
            ans = mid;
            low = mid;
        }
        else{
            high = mid;
        }
    }
    cout <<setprecision(10) <<ans;

    return 0;
}
