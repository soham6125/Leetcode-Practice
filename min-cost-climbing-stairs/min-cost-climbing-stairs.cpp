class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> dp(n+1,INT_MAX);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for(int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-1] + cost[i], dp[i-2] + cost[i]);
        }
        dp[n] = min(dp[n-2], dp[n-1]);
        return dp[n];
    }
};