#include <iostream>
#include <cctype>
#include <cstring>
using namespace std;

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string a,b; cins(a,b);
    long long s1 = 0, s2 =0;
    int n = a.length();
    for(int i=0; i<n; i++){
        char c =  tolower(a[i]);
        char d =  tolower(b[i]);
        if(c > d){
            coutn(1); return 0;
        }
        else if(c<d) {  coutn(-1); return 0; }
    }
    coutn(0);
    return 0;
}