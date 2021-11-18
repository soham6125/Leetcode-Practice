class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        unordered_map<int,int> m;
        for(auto it:nums) m[it]++;
        vector<int> ans;
        for(int i=1; i<=nums.size(); i++) 
        {
            if(m.find(i) == m.end()) ans.push_back(i);
        }
        return ans;
    }
};