class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        int len = words[0].length();
        int sz = words.size() * len;
        int n = s.length();
        if(n < sz) return ans;
        map<string, int> m1;
        for(auto it:words) m1[it]++;
        for(int i=0;i<=n-sz;i++)
        {
            string s1 = s.substr(i, sz);
            map<string, int> m2;
            for(int j=0;j<s1.size();j+=len) {
                string tmp = s1.substr(j, len);
                m2[tmp]++;
            }
            if(m1 == m2) ans.push_back(i);
        }
        return ans;
    }
};