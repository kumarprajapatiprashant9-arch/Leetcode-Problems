class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> mat(n, vector<int>(n));

        int left = 0, right = n - 1;
        int top = 0, bottom = n - 1;
        int k = 1;

        while(left <= right && top <= bottom){

            // Top row: left -> right
            for(int col = left; col <= right; col++){
                mat[top][col] = k++;
            }
            top++;

            // Right column: top -> bottom
            for(int row = top; row <= bottom; row++){
                mat[row][right] = k++;
            }
            right--;

            // Bottom row: right -> left
            for(int col = right; col >= left; col--){
                mat[bottom][col] = k++;
            }
            bottom--;

            // Left column: bottom -> top
            for(int row = bottom; row >= top; row--){
                mat[row][left] = k++;
            }
            left++;
        }

        return mat;
    }
};