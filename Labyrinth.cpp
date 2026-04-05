#include <bits/stdc++.h>
using namespace std;

const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};
const char dir[] = {'D', 'U', 'R', 'L'};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m; cin >> n >> m;
    vector<string> adj(n);
    for (int i = 0; i < n; i++) cin >> adj[i];

    pair<int, int> start, end;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (adj[i][j] == 'A') start = {i, j};
            if (adj[i][j] == 'B') end = {i, j};
        }

    vector<vector<bool>> vis(n, vector<bool>(m, false));
    vector<vector<pair<int, int>>> par(n, vector<pair<int, int>>(m, {-1, -1}));
    queue<pair<int, int>> q;
    vis[start.first][start.second] = true;
    q.push(start);

    bool found = false;
    while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        if (make_pair(x, y) == end) {
            found = true;
            break;
        }
        for (int d = 0; d < 4; d++) {
            int nx = x + dx[d], ny = y + dy[d];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !vis[nx][ny] && adj[nx][ny] != '#') {
                vis[nx][ny] = true;
                par[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }

    if (!found) {
        cout << "NO\n";
        return 0;
    }

    // Reconstruct path
    string path;
    pair<int, int> cur = end;
    while (cur != start) {
        auto [px, py] = par[cur.first][cur.second];
        for (int d = 0; d < 4; d++) {
            if (px + dx[d] == cur.first && py + dy[d] == cur.second) {
                path += dir[d];
                break;
            }
        }
        cur = {px, py};
    }
    reverse(path.begin(), path.end());
    cout << "YES\n" << path.size() << "\n" << path << "\n";
    return 0;
}