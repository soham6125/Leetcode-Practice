class Solution {
public:
    int n,m;
    int vis[7][7];
    
    bool dfs(int i,int j,int ind,vector<vector<char>> &board,string word)
    {
        if(i>=n or i<0 or j<0 or j>=m) return false;
        if(vis[i][j]) return false;
        if(word[ind] != board[i][j]) return false;
        if(ind==word.size()-1) return true;
        vis[i][j] = 1;
        bool ok = false;
        if(dfs(i+1,j,ind+1,board,word)) ok |= true;
        if(dfs(i-1,j,ind+1,board,word)) ok |= true;
        if(dfs(i,j+1,ind+1,board,word)) ok |= true;
        if(dfs(i,j-1,ind+1,board,word)) ok |= true;
        if(ok) return true;
        vis[i][j] = 0;
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n = board.size();
        m = board[0].size();
        memset(vis,0,sizeof(vis));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(dfs(i,j,0,board,word)) return true;
            }
        }
        return false;
    }
};