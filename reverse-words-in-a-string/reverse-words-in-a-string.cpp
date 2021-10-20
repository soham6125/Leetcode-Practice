#include<bits/stdc++.h>

class Solution {
public:
    string reverseWords(string str) {
        stringstream s(str); 
        string word; 
        vector<string> v;
        while(s >> word)
            v.push_back(word);
        string ans;
        reverse(v.begin(),v.end());
        for(auto it:v) ans += (it + ' ');
        ans.pop_back();
        return ans;
    }
};