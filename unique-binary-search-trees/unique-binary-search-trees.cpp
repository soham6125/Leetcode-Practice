class Solution {
public:
    int numTrees(int n) {
        vector<int> catalan(n+1,0);
        catalan[0] = 1;
        catalan[1] = 1;
        for(int i=2; i<=n; i++)
        {
            int ans = 0;
            for(int j=0; j<i; j++)
            {
                ans += catalan[j] * catalan[i-j-1];
            }
            catalan[i] = ans;
        }
        return catalan[n];
    }
};