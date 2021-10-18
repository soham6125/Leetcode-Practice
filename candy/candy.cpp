class Solution {
public:
    int candy(vector<int>& a) {
        int n = a.size();
        int totalCandies = 0;
        vector<int> dp(n , 1);
        for(int i = 1; i < n ; i++)
        {
            if(a[i-1]<a[i]) dp[i] = dp[i-1] + 1;
        }
        // for(auto it:dp) cout<<it<<" ";
        for(int i = n - 1; i > 0 ; i--)
        {
           if(a[i-1]>a[i] and dp[i-1]<=dp[i])
           {
               dp[i - 1] = dp[i] + 1;
           }
        }
        for(auto i : dp) totalCandies += i;
        return totalCandies;
    }
};