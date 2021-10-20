class Solution {
public:
    int minSubArrayLen(int x, vector<int>& v) {
        int sum = 0;
        int n = v.size();
        int i = 0, j = 0;
        int ans = INT_MAX;
        while(i<n)
        {
            sum += v[i];
            if(sum < x) i++;
            else 
            {
                ans = min(ans, i - j + 1);
                sum -= v[j];
                j++;
                sum -= v[i];
            }
        }
        if(ans == INT_MAX) return 0;
        else return ans;
    }
};