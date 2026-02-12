class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        
        int left = 0;
        int right = cols - 1;
        
        while (left <= right) {
            int mid = left + (right - left) / 2;
            
            // Step 1: Find max element in mid column
            int maxRow = 0;
            for (int r = 0; r < rows; r++) {
                if (mat[r][mid] > mat[maxRow][mid]) {
                    maxRow = r;
                }
            }
            
            int leftNeighbor = (mid - 1 >= 0) ? mat[maxRow][mid - 1] : -1;
            int rightNeighbor = (mid + 1 < cols) ? mat[maxRow][mid + 1] : -1;
            
            // Step 2: Check if it's a peak
            if (mat[maxRow][mid] > leftNeighbor &&
                mat[maxRow][mid] > rightNeighbor) {
                return {maxRow, mid};
            }
            
            // Step 3: Move toward bigger neighbor
            else if (leftNeighbor > mat[maxRow][mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return {-1, -1}; // Should never reach here
    }
};
