class Solution {
public:
    string minWindow(string s, string t) {
        string ans="";
        int i=0, j=0, ind=-1;
        int mx = INT_MIN;
        unordered_map<char,int> m1, m2;
        for(auto it:t) m2[it]++;
        while(i<s.length())
        {
            m1[s[i]]++;
            bool ok = true;
            for(auto it:m2)
            {
                ok &= (m1.find(it.first)!=m1.end());
                ok &= (m1[it.first] >= it.second);
            }
            if(!ok)
            {
                i++;
            }
            else
            {
                string tmp = s.substr(j,i-j+1);
                if(ans == "") ans = tmp;
                else if(ans!="" and tmp.size()<ans.size()) ans = tmp;
                m1[s[j]]--;
                if(m1[s[j]]==0) m1.erase(s[j]);
                j++;
                m1[s[i]]--;
                if(m1[s[i]]==0) m1.erase(s[i]);
            }
        }
        return ans;
    }
};