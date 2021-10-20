class Solution {
public:
    int findLength(vector<int>& v1, vector<int>& v2) {
        int n = v1.size();
        int m = v2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        int ans = 0;
        for(int i=0;i<=n;i++) {
            for(int j=0;j<=m;j++) {
                if(i==0 or j==0)
                {
                    dp[i][j] = 0;
                    continue;
                }
                else
                {
                    if(v1[i-1] == v2[j-1])
                    {
                        dp[i][j] = 1 + dp[i-1][j-1];
                        ans = max(ans, dp[i][j]);
                    }
                    else dp[i][j] = 0;
                }
            }
        }
        return ans;
    }
};