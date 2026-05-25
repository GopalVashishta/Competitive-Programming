#include<iostream>
using namespace std;

int main() {
    long long n; cin >> n;
    long long ans = 1e9;
    // well to make all multiplications == 0, 1 element should be zero
    // so select the element which is closest to 0 from both -ve and +ve side
    // and that value will be our no. of operations(coz in 1 opr we can +/- 1)
    for(int i=0; i<n; i++){
        long long a; cin >> a;
        ans = min(ans, abs(a));
    }
    cout << ans << " ";
    return 0;
}