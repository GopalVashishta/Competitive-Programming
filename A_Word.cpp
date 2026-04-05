#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <iomanip>
using namespace std;
#define fastio() ios::sync_with_stdio(false); cin.tie(nullptr)
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

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
    fastio(); //ios_base::sync_with_stdio(false);  cin.tie(NULL);
    string s; cin >> s;
    int ctu =0, ctl =0, n = s.length();
    for(int i=0; i<n; i++){
        if(s[i] >= 'A' && s[i] <= 'Z') ctu++;
        else ctl++;
    }
    bool flag = ctl >=ctu;
    for(int i = 0; i<n; i++){
        if(flag) s[i] = tolower(s[i]);
        else s[i] = toupper(s[i]);
    }
    coutn(s);
    return 0;
}