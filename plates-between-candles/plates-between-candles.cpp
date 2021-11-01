class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& q) {
        vector<int> v, res;
        for(int i=0;i<s.size();i++)
        {
            if(s[i] == '|') v.push_back(i);
        }
        // for(auto it:v) cout<<it<<" ";
        // cout<<endl;
        vector<int> pref(s.size());
        pref[0] = (s[0]=='*');
        for(int i=1;i<s.size();i++)
        {
            pref[i] = pref[i-1] + (s[i]=='*');
            
        }
        for(int i=0;i<q.size();i++)
        {
            int l = q[i][0];
            int r = q[i][1];
            // if(v.size() <= 1) 
            // {
            //     res.push_back(0);
            //     continue;
            // }
            int ind1 = lower_bound(v.begin(),v.end(),l) - v.begin();
            int ind2 = lower_bound(v.begin(),v.end(),r) - v.begin();
            if(ind2==v.size() or v[ind2]>r) ind2--;
            int ans = 0;
            // cout<<ind1<<" "<<ind2<<"->"<<endl;
            if(v[ind1]>=l and v[ind1]<=r and v[ind2]>=l and v[ind2]<=r)
            {
                ans += (pref[v[ind2]] - pref[v[ind1]]);;
            }
            res.push_back(ans);
        }
        return res;
    }
};