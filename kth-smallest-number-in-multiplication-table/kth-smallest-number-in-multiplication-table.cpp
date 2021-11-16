class Solution {
public:
    int solve(int m,int n,int k)
    {
        int ans = 0;
        for(int i=1; i<=m; i++)
        {
            int tot = k/i;
            if(tot > n) ans += n;
            else ans += tot;
        }
        return ans;
    }
    
    int findKthNumber(int m, int n, int k) {
        int l=1, r=m*n;
        int ans = 0;
        while(l <= r)
        {
            int mid = (l + r) / 2;
            int res = solve(m,n,mid);
            if(res < k) l = mid+1;
            else
            {
                ans = mid;
                r = mid-1;
            }
        }
        return ans;
    }
};