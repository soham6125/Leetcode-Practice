class Solution {
public:
    int maxHeight(vector<vector<int>>& c) {
        for(auto& t : c) sort(t.begin(), t.end());
        sort(c.begin(), c.end());
        vector<int> res(c.size(), 0);
        for(int i = 0; i < c.size(); i++) 
        {
            res[i] = c[i][2];
            for(int j = 0; j < i; j++) 
            {
                if(c[i][0]>=c[j][0] && c[i][1]>=c[j][1] && c[i][2]>=c[j][2])
                    res[i] = max(res[i], c[i][2] + res[j]);
            }
        }
        return *max_element(res.begin(), res.end());
    }
};