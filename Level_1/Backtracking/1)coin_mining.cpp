Reference-> Notebook 1 Page No. 51
for diagram

Question ->https://practice.geeksforgeeks.org/contest/gfg-weekly-coding-contest-140/instructions
question number 3.
Coin Mining.

Explaination-:
1)The helper function takes the current position (i, j) in the grid, the visited array to keep track 
of visited cells, and the size of the grid N.
2)It recursively explores all four possible directions (up, down, left, right) from the current 
  cell (i, j) while ensuring that it doesnot go out of bounds or revisit already visited cells.
3)It returns the maximum number of coins collected starting from the current cell (i, j).
4) The maximumCoins function initializes the answer variable ans to 0.
5)It initializes the visited array dynamically based on the size of the grid.
6)It iterates through all cells in the grid and calls the helper function for each cell, updating the answer variable with the maximum number of coins collected.
7)Finally, it returns the maximum number of coins collected.



Code-:
int helper(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited, int N) {
    // Check if the cell is out of bounds or already visited
    if (i < 0 || i >= N || j < 0 || j >= N || visited[i][j] || grid[i][j] == 0)
        return 0;

    // Mark the cell as visited
    visited[i][j] = true;

    // Explore four possible directions
    int up = helper(grid, i - 1, j, visited, N);
    int down = helper(grid, i + 1, j, visited, N);
    int left = helper(grid, i, j - 1, visited, N);
    int right = helper(grid, i, j + 1, visited, N);

    // Unmark the cell (backtrack)
    visited[i][j] = false;

    // Return the maximum coins collected including the current cell
    return grid[i][j] + max(up, max(down, max(left, right)));
}
    
    int maximumCoins(int N, vector<vector<int>> &grid) {
        // Initialize answer
    int ans = 0;

    // Initialize visited array dynamically
    vector<vector<bool>> visited(N, vector<bool>(N, false));

    // Iterate through the grid and find maximum coins
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int index = i + j;
            if (index % 2 != 0 && grid[i][j] != 0)
                ans = max(ans, helper(grid, i, j, visited, N));
        }
    }

    // Return the maximum coins collected
    return ans;
    } 