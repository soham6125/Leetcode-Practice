class Solution {
public:
    vector<int> computeLPSArray(string str)
    {
        int M = str.length();
        vector<int> lps(M);
        int len = 0;
        lps[0] = 0; 
        int i = 1;
        while (i < M)
        {
            if (str[i] == str[len])
            {
                len++;
                lps[i] = len;
                i++;
            }
            else 
            {
                if (len != 0)
                {
                    len = lps[len-1];
                }
                else
                {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }
    
    string shortestPalindrome(string s) {
        string revStr = s;
        reverse(revStr.begin(), revStr.end());
        string concat = s + "$" + revStr;
        vector<int> lps = computeLPSArray(concat);
        int sz = s.size() - (s.length() - lps.back());
        string tmp = s.substr(sz);
        reverse(tmp.begin(), tmp.end());
        string ans = tmp + s;
        return ans;
    }
};