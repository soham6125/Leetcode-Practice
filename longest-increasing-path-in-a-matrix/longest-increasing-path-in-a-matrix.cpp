class Solution {
public:
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int row,int col,int prev)
    {
        if(row<0 or col<0 or row>=matrix.size() or col>=matrix[0].size() ) return 0;
        if(matrix[row][col]<=prev) return 0;
        else if(dp[row][col]) return dp[row][col];
        int left_sub  = dfs(matrix,dp,row,col-1,matrix[row][col]);
        int right_sub = dfs(matrix,dp,row,col+1,matrix[row][col]);
        int top_sub   = dfs(matrix,dp,row-1,col,matrix[row][col]);
        int down_sub  = dfs(matrix,dp,row+1,col,matrix[row][col]);   
        dp[row][col] = 1 + max({left_sub,right_sub,top_sub,down_sub});
        return dp[row][col];
    }
    
    int longestIncreasingPath(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<vector<int>> dp (row,vector<int>(col,0));
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++) {   
                dp[i][j] = dfs(matrix,dp,i,j,INT_MIN);
            }
        }
        int maximum = INT_MIN;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)    
                maximum = max(maximum, dp[i][j]); 
        }
        return maximum;
    }
};