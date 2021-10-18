class Solution {
public:
    int getXORSum(vector<int>& a, vector<int>& b) {
        int x = 0;
        for(int i=0;i<b.size();i++)
        {  
            if(i==0) x=b[i];
            else x^=b[i];
        }
        int ans = 0;
        for(int i=0;i<a.size();i++)
        {
            int tmp = a[i]&x;
            if(i==0) ans=tmp;
            else ans^=tmp;
        }
        return ans;
    }
};