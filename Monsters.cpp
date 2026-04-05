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


const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'D', 'U', 'R', 'L'};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for (int i = 0; i < n; ++i) cin >> grid[i];

    vector<vector<int>> monst(n, vector<int>(m, INT_MAX));
    queue<pair<int, int>> mq;
    pair<int, int> start;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < m; ++j) {
            if (grid[i][j] == 'M') {
                mq.push({i, j});
                monst[i][j] = 0;
            }
            if (grid[i][j] == 'A') start = {i, j};
        }

    // Multi-source BFS for monsters
    while (!mq.empty()) {
        auto [x, y] = mq.front(); mq.pop();
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] != '#' && monst[nx][ny] > monst[x][y] + 1) {
                monst[nx][ny] = monst[x][y] + 1;
                mq.push({nx, ny});
            }
        }
    }

    vector<vector<int>> player(n, vector<int>(m, INT_MAX));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> pq;
    pq.push(start);
    player[start.first][start.second] = 0;

    pair<int, int> escape = {-1, -1};
    while (!pq.empty()) {
        auto [x, y] = pq.front(); pq.pop();
        // Check if at boundary
        if (x == 0 || x == n-1 || y == 0 || y == m-1) {
            escape = {x, y};
            break;
        }
        for (int d = 0; d < 4; ++d) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m &&
                grid[nx][ny] != '#' &&
                player[nx][ny] == INT_MAX &&
                player[x][y] + 1 < monst[nx][ny]) {
                player[nx][ny] = player[x][y] + 1;
                par[nx][ny] = {x, y};
                pq.push({nx, ny});
            }
        }
    }

    if (escape.first == -1) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    pair<int, int> cur = escape;
    while (cur != start) {
        auto [px, py] = par[cur.first][cur.second];
        for (int d = 0; d < 4; ++d) {
            if (px + dx[d] == cur.first && py + dy[d] == cur.second) {
                path += dir[d];
                break;
            }
        }
        cur = {px, py};
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << "\n" << path << "\n";
}