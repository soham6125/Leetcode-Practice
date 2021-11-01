class Solution {
public:
    int minimumOperations(vector<int>& nums, int start, int goal) {
        vector<bool> vis(1010,false);
        int ans = 0;
        queue<int> q;
        q.push(start);
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                if(node==goal) return ans;
                if(node>1000 or node<0 or vis[node]) continue;
                vis[node] = true;
                for(int i=0;i<nums.size();i++)
                {
                    int a=node+nums[i];
                    int b=node-nums[i];
                    int c=node^nums[i];
                    q.push(a);
                    q.push(b);
                    q.push(c);
                }
            }
            ans++;
        }
        return -1;
    }
};