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
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}


using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,k; cins(n,k);
    vector<int> arr(n); cinv(arr);
    int l = 0, r = 0,ct =0;
    ll sum = 0;
    
    while (r < n) {
        sum += arr[r];
        while (sum > k && l <= r) {
            sum -= arr[l];
            l++;
        }
        if (sum == k) ct++;
        r++;
    }

    couts(ct);
    /* 
    unordered_map<ll, int> map;
    ll sum = 0;
    for(int i=0; i<n; i++){
        sum +=arr[i];
        if(map.find(sum - k) != map.end()){
            map[k]++;
        }
        map[sum]++;
    }
    if(map.find(sum - k) == map.end()){ couts(0); return 0;}
    couts(map[k]);
    */
    return 0;
}