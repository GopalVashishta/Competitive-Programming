#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ; cin >> s;
    s[0] = toupper(s[0]);
    coutn(s);
    return 0;
}