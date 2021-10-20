class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        sort(v.begin(),v.end());
        vector<vector<int>> ans;
        int start = v[0][0], end = v[0][1];
        for(int i=1;i<v.size();i++)
        {
            if(end>=v[i][0]) end = max(end,v[i][1]);
            else
            {
                vector<int> tmp;
                tmp.push_back(start);
                tmp.push_back(end);
                ans.push_back(tmp);
                start = v[i][0];
                end = v[i][1];
            }
        }
        vector<int> tmp;
        tmp.push_back(start);
        tmp.push_back(end);
        ans.push_back(tmp);
        return ans;
    }
};