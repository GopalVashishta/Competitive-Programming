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
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;


int main() {
    fastio(); //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        int n; cin >>n; // for a particular l and r;
        vector<int> arr(n); cinv(arr);
       unordered_map<int, int> omp, emp;
        long long sum = 0, sm = 0;
        bool ans = false;

        for (int i = 1; i < n; i += 2) {
            sum += arr[i - 1];
            sm += arr[i];
            
            omp[sum]++;
            emp[sm]++;
            
            if (omp.find(sm) != omp.end()) {
                ans = true;
                break; 
            }
        }
        if(ans) coutn("YES");
        else coutn("NO");
    }
    return 0;
}