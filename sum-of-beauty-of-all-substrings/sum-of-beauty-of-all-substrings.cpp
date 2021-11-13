class Solution {
public:
    int beautySum(string s) {
        int n = s.length();
        int ans = 0;
        map<char,int> m;
        for(int i=0; i<n; i++) 
        {
            m.clear();
            for(int j=i; j<n; j++) 
            {
                m[s[j]]++;
                int mx = INT_MIN, mn = INT_MAX;
                for(auto it:m) 
                {
                    mx = max(mx, it.second);
                    mn = min(mn, it.second);
                }
                ans += (mx - mn);
            }
        }
        return ans;
    }
};