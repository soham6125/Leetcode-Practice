class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(n == 1) return 0;
        int ans = INT_MIN;
        for(int i=1;i<n;i++)
        {
            ans = max(ans, nums[i]-nums[i-1]);
        }
        return ans;
    }
};