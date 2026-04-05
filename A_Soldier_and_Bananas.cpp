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
    int k,n,w; cins(k,n,w);
    ll total = k*(w*(w+1)/2);
    total = (total -n > 0) ? total -n:0;
    coutn(total);
    return 0;
}