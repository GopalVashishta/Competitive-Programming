#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}

template<typename... T> void cins(T&... args) { ((cin >> args), ...);}
template<typename... T> void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;


#if __cplusplus >= 201703L
    #define GCD(a, b) std::gcd((a), (b))
#else
    template<typename T>
    T GCD(T a, T b) { while (b) { T t = b; b = a % b; a = t; } return a; }
#endif



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

int main() {
    fast;
    int n , m; cins(n, m);
    vector<int> a(n), b(m);
    cinv(a); cinv(b);

    ll ans= 0;
    int i=0, j =0;
    while(i<n && j<m){
        if(a[i] < b[j]){
            i++;
        }
        else if( a[i] > b[j]){
            j++;
        }
        else {
            ll cnta = 0, cntb = 0;
            int val = a[i];

            while (i < n && a[i] == val) {
                cnta++;
                i++;
            }
            while (j < m && b[j] == val) {
                cntb++;
                j++;
            }
            ans += cnta * cntb;
        }
    }

    cout << ans << " ";
    return 0;
}