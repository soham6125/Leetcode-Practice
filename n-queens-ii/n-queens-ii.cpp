class Solution {
public:
    int ans;
    bool check(vector<string> & board,int row, int col, int n)
    {
        for(int i=0;i<n;i++) {
            if(board[row][i]=='Q' || board[i][col]=='Q') 
                return false;
        }
        // diagonal one
        int r = row;
        int c = col;
        while(r<n and c<n) {  
            if(board[r++][c++]=='Q') return false;
        }
        // diagonal 2
        r = row;
        c = col;
        while(r>=0 and c>=0) {
            if(board[r--][c--]=='Q') return false;
        }
        // diagonal 3
        r = row;
        c = col;
        while(r>=0 && c<n) {
            if(board[r--][c++]=='Q') return false;
        }
        // diagonal 4
        r = row;
        c = col;
        while(r<n && c>=0) {  
            if(board[r++][c--]=='Q') return false;
        }
        return true;
    }
    
    void solve(vector<string> & board,int n,int col)
    {
        if(col==n) {
            ans++;
            return; 
        }
        for(int row=0;row<n;row++)
        {
            if(check(board,row,col,n))
            {
                board[row][col] = 'Q';
                solve(board,n,col+1);
                board[row][col] = '.';
            }
        }    
    }
    
    int totalNQueens(int n) {
        ans = 0;
        vector<string> board(n);
        string s(n,'.');
        for(int i=0;i<n;i++) board[i] = s;
        solve(board,n,0);
        return ans;
    }
};
