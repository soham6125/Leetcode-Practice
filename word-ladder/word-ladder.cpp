class Solution {
public:
    bool check(string s1, string s2)
    {
        int n = s1.length(), m = s2.length();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(s1[i] != s2[i]) cnt++;
            if(cnt >= 2) return false;
        }
        return true;
    }
    
    int ladderLength(string s1, string s2, vector<string>& v) {
        int n = v.size();
        vector<bool> vis(n,false);
        queue<pair<int,string>> qu;
        qu.push({1,s1});
        int ans = INT_MAX;
        while(!qu.empty())
        {
            pair<int,string> p = qu.front();
            qu.pop();
            for(int i=0; i<n; i++)
            {
                if(!vis[i])
                {
                    if(check(p.second,v[i]) and v[i]==s2)
                    {
                        ans = min(ans, p.first+1);
                    }
                    else if(check(p.second,v[i]) and v[i]!=s2)
                    {
                        qu.push({p.first+1,v[i]});
                        vis[i] = true;
                    }
                }
            }
        }
        return (ans==INT_MAX ? 0 : ans);
    }
};