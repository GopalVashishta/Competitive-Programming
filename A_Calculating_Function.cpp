#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll n ; cin >> n;
    ll odd = (n&1) ? ceil((double)n/2): n/2;
    ll even = floor(n/2);
    odd = odd*odd, even = even*(even+1);
    ll ans = even-odd;
    cout << ans;
}