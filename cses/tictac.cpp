#include <bits/stdc++.h>
using namespace std;

void show(const vector<vector<char>>& grid) {
    for (auto x : grid) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    const int n = 3;
    const int ns = n * n;
    vector<vector<char>> grid(n, vector<char>(n, '.'));

    // Player 1 moves add +1; Player 2 moves add -1
    vector<int> row_scores(n, 0);
    vector<int> col_scores(n, 0);
    int diag_score = 0;
    int anti_diag_score = 0;

    int turn = 0; // 0 for Player 1 (P1), 1 for Player 2 (P2)
    char p1c, p2c;
    
    cout << "Enter Character for P1 and P2\n";
    if (!(cin >> p1c >> p2c)) return 0;

    int cnt = 0;
    while (true) {
        int x, y;
        cout << "Enter Move for Player:" << (!turn ? "P1" : "P2") << "\n";
        if (!(cin >> x >> y)) break;

        if (x < 0 || y < 0 || x >= n || y >= n || grid[x][y] != '.') {
            cout << "Please Enter a Valid Move\n";
            continue;
        }

        grid[x][y] = (!turn) ? p1c : p2c;
        cnt++;
        cout << "\n";
        show(grid);

        int score_delta = (!turn) ? 1 : -1;
        row_scores[x] += score_delta;
        col_scores[y] += score_delta;

        if (x == y) {
            diag_score += score_delta;
        }
        if (x + y == n - 1) {
            anti_diag_score += score_delta;
        }

        int target_score = (!turn) ? n : -n;
        bool has_won = (row_scores[x] == target_score || 
                        col_scores[y] == target_score || 
                        (x == y && diag_score == target_score) || 
                        (x + y == n - 1 && anti_diag_score == target_score));

        if (has_won) {
            cout << (!turn ? "P1" : "P2") << " Won!\n";
            break;
        } else if (cnt == ns) {
            cout << "TIE\n";
            break;
        } else {
            cout << "Game continues...\n";
        }

        turn = !turn;
    }

    return 0;
}