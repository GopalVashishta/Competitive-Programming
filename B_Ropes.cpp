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
    for(auto &x: arr) cin>>x;
    double ans = 0.0;
    double low = 0.0, high = *max_element(arr.begin(), arr.end());
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
