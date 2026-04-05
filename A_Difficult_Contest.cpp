#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <functional>
#include <utility>
#include <iterator>
#include <cstring>
#include <string>
#include <cmath>
#include <math.h>
#include <bitset>
#include <list>
#include <cassert>
#include <climits>
#include <cfloat>
#include <numeric>
#include <iomanip>
using namespace std;
#define cinarr(a,x,y) for(int i=x;i<y;i++){cin>>a[i];}
#define cinvec(v,n) for(int i=0;i<n;i++){int x; cin>>x; v.push_back(x);}
#define cinv(v) for(auto &x: v){cin>>x;}
#define cinset(s,n) for(int i=0;i<n;i++){int x; cin>>x; s.insert(x);}

template<typename... T>
void cins(T&... args) { ((cin >> args), ...);}
template<typename... T>
void couts(T&&... args) { ((cout << args << " "), ...);}
template<typename... T>
void coutnl(T&&... args) { ((cout << args << " "), ...); cout<<'\n';}
template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

#define PI 3.14159265358979323846

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        string s; cin >>s;
        map<char, int> counts;
        for (char c = 'A'; c <= 'Z'; ++c) {
            counts[c] = 0;
        }
        
        for (char ch : s) {
            counts[ch]++;
        }
        
        string result = "";
        
        for (int i = 0; i < counts['T']; ++i) {
            result += 'T';
        }
        for (int i = 0; i < counts['F']; ++i) {
            result += 'F';
        }
        
        for (int i = 0; i < counts['N']; ++i) {
            result += 'N';
        }
        
        for (char ch = 'A'; ch <= 'Z'; ++ch) {
            if (ch != 'F' && ch != 'N' && ch != 'T') {
                for (int i = 0; i < counts[ch]; ++i) {
                    result += ch;
                }
            }
        }
            
        coutn(result);
    }
    return 0;
}