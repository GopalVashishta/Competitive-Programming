#include <iostream>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
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
        ll a,b; cins(a,b);
        ll ans = min(a,min(b,(a+b)/4));
        coutn(ans);
    }
    return 0;
}