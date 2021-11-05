class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, ans = 0;
        for(int i=0;i<n;i++) {
            gas[i] -= cost[i];
            sum += gas[i];
        }
        if(sum < 0) return -1;
        sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += gas[i];
            if(sum < 0)
            {
                sum = 0;
                ans = i+1;
            }
        }
        return ans;
    }
};