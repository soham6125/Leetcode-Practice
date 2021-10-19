class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int result = 0;
        for(int i=0;i<points.size();i++)
        {
            unordered_map<long double,int> mp;
            int mx = 0;
            for(int j=i+1;j<points.size();j++)
            {
                if(points[i][0]==points[j][0])
                {
                    mp[INT_MAX]++;
                }
                else
                {
                    long double slope = (long double)(points[i][1]-points[j][1]) / (long double)(points[i][0]-points[j][0]);
                    mp[slope]++;
                }
            }
            for(auto i : mp)
            {
                mx = max(mx, i.second);
            }
            mx++;
            result = max(result,mx);  
        }
        return result;
    }
};