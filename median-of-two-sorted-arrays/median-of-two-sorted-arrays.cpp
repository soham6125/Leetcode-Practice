class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        double median = 0;
        vector<double> res(n+m);
        int i = 0,j = 0, ind = 0;
        while(i<n && j<m)
        {
            if(nums1[i] < nums2[j])
            {
                res[ind++] = nums1[i++];
            }
            else
            {
                res[ind++] = nums2[j++];
            }
        }
        while(i<n)
        {
            res[ind++] = nums1[i++];
        }
        while(j<m)
        {
            res[ind++] = nums2[j++];
        }
        if((n+m)%2==0)
        {
            int x = (n+m)/2;
            double y = res[x];
            double z = res[x-1];
            median = (y+z)/2;
        }
        else
        {
            int x = (n+m)/2;
            median = res[x];
        }
        return median;
    }
};