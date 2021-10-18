class Solution {
public:
    int largestRectangleArea(vector<int>& h) 
    {
        int area=0,i;
        stack<int>stk;
        h.push_back(-1);
        for(i=0;i<h.size();i++)
        {
            while(!stk.empty() && h[stk.top()]>h[i])
            {
                int top=stk.top();
                stk.pop();
                if(stk.empty())
                {
                    area=max(area,i*h[top]);
                }
                else
                {
                    area=max(area,(i-stk.top()-1)*h[top]);
                }
            }
            stk.push(i);
        }
        return area;
    }

    int maximalRectangle(vector<vector<char>>& mat) 
    {
        if(mat.size()==0) return 0;
        int m=mat.size(),n=mat[0].size();
        vector<vector<int>>grid(m,vector<int>(n,0));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==0)
                    grid[i][j]=mat[i][j]-'0';
                else if(mat[i][j]=='1')
                {
                    grid[i][j]+=grid[i-1][j]+1;
                }
            }
        }
        int res=0;
        for(int i=0;i<m;i++) res=max(res,largestRectangleArea(grid[i]));
        return res;
    }

};