class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        vector<int> first, second;
        if(nums.size() == 1) return;
        sort(nums.begin(),nums.end());
        if(nums.size() % 2)
        {
            for(int i=0;i<=nums.size()/2;i++) first.push_back(nums[i]);
            for(int i=nums.size()/2 + 1;i<nums.size();i++) second.push_back(nums[i]);
            reverse(second.begin(),second.end());
        }
        else
        {
            for(int i=0;i<nums.size()/2;i++) first.push_back(nums[i]);
            for(int i=nums.size()/2;i<nums.size();i++) second.push_back(nums[i]);
            reverse(second.begin(),second.end());
        }
        int i = 0, j = 0;
        int ind = 0;
        while(ind<nums.size())
        {
            nums[ind] = first[i];
            i++; ind++;
            if(ind == nums.size()) break;
            nums[ind] = second[j];
            j++; ind++;
        }
        bool ok = true;
        for(int i=1;i<nums.size()-1;i++)
        {
            if(i%2) ok &= (nums[i]>nums[i-1] and nums[i]>nums[i+1]);
            else ok &= (nums[i]<nums[i-1] and nums[i]<nums[i+1]);
        }
        // cout << (ok ? "yes" : "no");
        if(ok) return;
        reverse(first.begin(),first.end());
        i=0; j=0;
        ind = 0;
        while(ind<nums.size())
        {
            nums[ind] = first[i];
            i++; ind++;
            if(ind == nums.size()) break;
            nums[ind] = second[j];
            j++; ind++;
        }
    }
};