/*
According to Wikipedia's article: "The Game of Life, also known simply as Life, is a cellular automaton devised by the British mathematician John Horton Conway in 1970."

The board is made up of an m x n grid of cells, where each cell has an initial state: live (represented by a 1) or dead (represented by a 0). Each cell interacts with its eight neighbors (horizontal, vertical, diagonal) using the following four rules (taken from the above Wikipedia article):

Any live cell with fewer than two live neighbors dies as if caused by under-population.
Any live cell with two or three live neighbors lives on to the next generation.
Any live cell with more than three live neighbors dies, as if by over-population.
Any dead cell with exactly three live neighbors becomes a live cell, as if by reproduction.
The next state is created by applying the above rules simultaneously to every cell in the current state, where births and deaths occur simultaneously. Given the current state of the m x n grid board, return the next state.
*/

//leetcode problem 289

class Solution {
public:
    void gameOfLife(vector<vector<int>>& arr) {
    int m = arr.size();
    int n = arr[0].size();
    vector<vector<int>> ans(m, vector<int>(n));

    // Directions for neighboring cells
    int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            int count = 0; // Count of live neighbors

            // Check all 8 neighboring cells
            for(int k = 0; k < 8; k++) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                
                // Check if neighboring cell is valid and alive
                if(ni >= 0 && ni < m && nj >= 0 && nj < n && arr[ni][nj] == 1) {
                    count++;
                }
            }

            // Apply rules of the game
            if(arr[i][j] == 1 && (count < 2 || count > 3)) {
                ans[i][j] = 0; // Cell dies due to underpopulation or overpopulation
            }
            else if(arr[i][j] == 0 && count == 3) {
                ans[i][j] = 1; // Cell becomes alive due to reproduction
            }
            else {
                ans[i][j] = arr[i][j]; // Cell remains in its current state
            }
        }
    }

    // Copy updated values from ans to arr
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < n; j++) {
            arr[i][j] = ans[i][j];
        }
    }
}

};