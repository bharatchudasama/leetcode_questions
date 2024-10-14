//tabulation
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        
        // Start iterating from the second last row to the top row
        for (int r = n - 2; r >= 0; r--) {
            for (int c = 0; c < n; c++) {
                // For each cell, calculate the minimum path sum of the next row cells
                int down = matrix[r + 1][c]; // Downward
                int leftDiag = (c > 0) ? matrix[r + 1][c - 1] : INT_MAX; // Left diagonal
                int rightDiag = (c < n - 1) ? matrix[r + 1][c + 1] : INT_MAX; // Right diagonal
                
                // Update the current cell with the minimum path sum
                matrix[r][c] += min(down, min(leftDiag, rightDiag));
            }
        }

        // The answer will be the minimum value in the first row
        int mini = INT_MAX;
        for (int i = 0; i < n; i++) {
            mini = min(mini, matrix[0][i]);
        }

        return mini;
    }
};
