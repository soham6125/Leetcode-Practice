class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        vector<int> prefix(n+1,0), suffix(n+1,0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            prefix[i+1] = sum;
        }
        sum = 0;
        for (int i = nums.size() - 1; i >= 0; i--) {
            sum += nums[i];
            suffix[i] = sum;
        }
        reverse(suffix.begin(),suffix.end());
        if(sum < x) return -1;
        int ans = INT_MAX;
        for(int i = 0; i < n+1; i++) 
        {
            int rem = x - prefix[i];
            int ind = lower_bound(suffix.begin(), suffix.end(), rem) - suffix.begin();
            if(suffix[ind] == rem) ans = min(ans, i + ind);
        }
        if(ans == INT_MAX) return -1;
        else return ans;
    }
};