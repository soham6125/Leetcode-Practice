class Solution {
public:
    int merge(vector<int>& a,int left,int mid,int right)
    {
        int inv_count = 0;
        int l = left, r = mid + 1;
        while(l <= mid && r <= right)
        {
            if((long)a[l] > (long) 2 * a[r])
            {
                inv_count += (mid - l + 1);
                r++;
            }
            else
            {
                l++;
            }
        } 
        sort(a.begin() + left, a.begin() + right + 1);
        return inv_count;
    }

    int mergesort(vector<int>& a,int left,int right)
    {
        int mid=0, inv_count=0;
        if(right > left)
        {
            mid = (left+right) / 2;
            inv_count += mergesort(a,left,mid);
            inv_count += mergesort(a,mid+1,right);
            inv_count += merge(a,left,mid,right);
        }
        return inv_count;
    }
    
    int reversePairs(vector<int>& nums) {
        int ans = mergesort(nums,0,nums.size()-1);
        return ans;
    }
};