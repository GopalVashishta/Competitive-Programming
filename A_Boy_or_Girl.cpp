#include <iostream>
#include <cstring>
#include <set>
#include <string>
using namespace std;
template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s; cin >> s; int n = s.length();
    set<char> st;
    for(int i =0; i <n; i++) st.insert(s[i]);
    int val = st.size();
    if(val & 1) coutn("IGNORE HIM!");
    else coutn("CHAT WITH HER!");
    return 0;
}