class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size(),ans;
        int mark[n+2];
        for(int i=1;i<=n+1;i++) mark[i]=0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0 and nums[i]<=n) mark[nums[i]]=1;
        }
        for(int i=1;i<=n+1;i++)
        {
            if(!mark[i]) 
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};