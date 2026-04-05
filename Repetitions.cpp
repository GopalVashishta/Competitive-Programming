#include <iostream>
#include <cstring>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

template<typename... T> void coutn(T&&... args) { ((cout << args << "\n"), ...);}

using ld = long double;
using ll = long long;


int main() {
    fast;
    string s; cin >> s;
    int mx = 1, cc = 1;
    for (size_t i = 1; i <(int) s.length(); ++i) {
        if (s[i] == s[i - 1]) {
            cc++;
            if (cc > mx)
                mx = cc;
        } else {
            cc = 1;
        }
    }
    coutn(mx);
    return 0;
}