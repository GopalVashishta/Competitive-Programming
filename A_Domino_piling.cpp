#include <iostream>
#include <numeric>
#include <iomanip>
using namespace std;

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}
using ll = long long;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,m; cins(n,m);
    ll ans = (n*m)/2;
    coutn(ans);
    return 0;
}