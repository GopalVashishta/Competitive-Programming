#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}
template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}

using ll = long long;
ll md(ll x2, ll y2, ll x1,ll y1){
    return abs(x2-x1)+abs(y2-y1);
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        long long xA, yA; long long xB, yB;
        long long xC, yC;
        cins(xA,yA);  cins(xB,yB); cins(xC,yC);
        ll AB = md(xA,yA,xB,yB);
        ll AC = md(xA,yA,xC,yC);
        ll BC = md(xB,yB,xC,yC);
        ll s  = AB +AC - BC;
        coutn((s/2)+1);
    }

    return 0;
}