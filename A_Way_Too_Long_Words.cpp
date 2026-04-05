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

template<typename... T>
void coutn(T&&... args) { ((cout << args << '\n'), ...);}

using ld = long double;
using ll = long long;
using ull = unsigned long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while(t--){
        string s; cin >> s;
        if(s.length() <= 10){ coutn(s); continue;}
        string ans = s[0]+to_string(s.length()-2)+s[s.length()-1];
        coutn(ans);
    }
    return 0;
}