class CombinationIterator {
public:
    vector<string> v;
    string s;
    CombinationIterator(string characters, int combinationLength) {
        s = characters;
        for(int i=0; i<(1<<s.size()); i++)
        {
            int x = i;
            int cnt = __builtin_popcount(x);
            if(cnt == combinationLength)
            {
                string fin;
                for(int j=0; j<s.size(); j++)
                {
                    if(i & (1<<j)) fin += s[j];
                }
                // reverse(fin.begin(), fin.end());
                v.push_back(fin);
            }
        }
        sort(v.begin(), v.end(), greater<string>());
    }
    
    string next() {
        string ans = v.back();
        v.pop_back();
        return ans;
    }
    
    bool hasNext() {
        if(v.size() > 0) return true;
        else return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */