class Solution {
public:
    vector<int> powerfulIntegers(int x, int y, int bound) {
        set<int> s;
        for(int i = 0; i <= sqrt(bound); i++)
        {
            for(int j = 0; j <= sqrt(bound); j++)
            {
                if(pow(x, i) > bound) break;
                if(pow(y, j) > bound) break;
                int k = pow(x, i) + pow(y, j);
                if(k <= bound)
                {
                    s.insert(k);
                }
            }
        }
        vector<int> v;
        for(auto it:s) v.push_back(it);
        return v;
    }
};