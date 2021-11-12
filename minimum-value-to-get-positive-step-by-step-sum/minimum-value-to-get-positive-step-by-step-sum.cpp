class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int sum = 0;
        int mn = INT_MAX;
        for(auto it:nums) {
            sum += it;
            mn = min(mn, sum);
        }
        if(mn <= 0) mn = (-1)*mn + 1;
        else mn = 1;
        return mn;
    }
};