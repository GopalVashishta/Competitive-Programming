#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
using namespace std;
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n ; cin >>n; 
    int x = 0;
    while(n--){
        string s; cin >> s;
        if(s[0] == '+' || s[1] == '+') x++;
        else x--;
    }
    coutn(x);
    return 0;
}