#include <iostream>
#include<vector>
#include <cstring>
using namespace std;

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    string s; cin >> s;
    int ct =0;
    for (int i = 1; i < n; ++i) {
        if (s[i] == s[i-1]) {
            ct++;
        }
    }
    coutn(ct);
    return 0;
}