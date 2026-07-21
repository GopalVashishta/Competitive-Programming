#include <bits/stdc++.h>
using namespace std;

#define fast do { ios::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr); } while(0)

void show(const vector<vector<int>>& grid) {
    for (int i = 0; i < grid.size(); ++i) {
        for (int j = 0; j < grid[0].size(); ++j) {
            cout << grid[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------\n";
}

bool check(const vector<vector<int>>& grid, int player) {
    int n = grid.size();
    int m = grid[0].size();
    
    // Check horizontal
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            if (grid[i][j] == player && grid[i][j+1] == player && 
                grid[i][j+2] == player && grid[i][j+3] == player)
                return true;
        }
    }
    
    // Check vertical
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m; j++) {
            if (grid[i][j] == player && grid[i+1][j] == player && 
                grid[i+2][j] == player && grid[i+3][j] == player)
                return true;
        }
    }
    
    // Check diagonal (top-left to bottom-right)
    for (int i = 0; i < n - 3; i++) {
        for (int j = 0; j < m - 3; j++) {
            if (grid[i][j] == player && grid[i+1][j+1] == player && 
                grid[i+2][j+2] == player && grid[i+3][j+3] == player)
                return true;
        }
    }
    
    // Check diagonal (bottom-left to top-right)
    for (int i = 3; i < n; i++) {
        for (int j = 0; j < m - 3; j++) {
            if (grid[i][j] == player && grid[i-1][j+1] == player && 
                grid[i-2][j+2] == player && grid[i-3][j+3] == player)
                return true;
        }
    }
    
    return false;
}

int main() {
    fast;
    int n = 6, m = 7;
    vector<vector<int>> grid(n, vector<int>(m, 0));
    int turn = 0;
    int total_moves = 0;
    
    cout << "Connect 4 Game!\n";
    show(grid);
    
    while(true){
        int player = turn + 1;
        cout << "Player " << player << " turn. Enter column (0 to " << m - 1 << "): ";
        
        int col; 
        cin >> col;
        
        if(col < 0 || col > m - 1){ 
            cout << "Invalid Input\n"; 
            continue;
        }
        
        int r = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (grid[i][col] == 0) {
                r = i;
                break;
            }
        }
        
        // If the column is completely full
        if (r == -1) {
            cout << "Column is full.\n";
            continue;
        }
        
        grid[r][col] = player;
        total_moves++;
        
        show(grid);
        
        // Check for win condition
        if (check(grid, player)) {
            cout << "Player " << player << " wins!\n";
            break;
        }

        if (total_moves == n * m) {
            cout << "The game is a draw!\n";
            break;
        }

        turn = !turn;
    }
    return 0;
}