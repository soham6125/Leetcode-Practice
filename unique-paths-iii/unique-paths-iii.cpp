class Solution {
public:
    int res = 0;
    int empty = 0;

    void dfs(vector<vector<int>> &grid, int x, int y, int count)
    {
        if(x<0 or y<0 or x>=grid.size() or y>=grid[0].size() or grid[x][y]==-1) return ;
        if(grid[x][y] == 2)
        {
            if(count==empty) res++;
            return;
        }
        grid[x][y] = -1;
        dfs(grid,x+1,y,count+1);
        dfs(grid,x-1,y,count+1);
        dfs(grid,x,y+1,count+1);
        dfs(grid,x,y-1,count+1);
        grid[x][y] = 0;
        return;
    }
    
    int uniquePathsIII(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ind1 = 0, ind2 = 0;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(mat[i][j] == 1)
                {
                    ind1 = i;
                    ind2 = j;
                }
                else if(mat[i][j]==0) empty++;
            }
        }
        // cout<<ind1<<" "<<ind2;
        dfs(mat, ind1, ind2, -1);
        return res;
    }
};