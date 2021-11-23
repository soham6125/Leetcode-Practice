class DSU
{
public:
    vector<int> parent, sz;
    int n;
    DSU( int n)
    {
        this->n = n;
        parent.resize(n);
        sz.resize(n);
    }
    void init()
    {
        for(int i = 0; i < n; i++)
        {
            parent[i] = i;
            sz[i] = 1;
        }
    }
    int find_set(int a)
    {
        if(parent[a] == a) return a;
        return parent[a] = find_set(parent[a]);
    }
    int union_set(int a,int b)
    {
        a = find_set(a);
        b = find_set(b);
        if(a==b)
        {
            return -1;
        }
        if(sz[a] < sz[b])
            swap(a, b);
        parent[b] = parent[a];
        sz[a] += sz[b];
        return a;
    }
};

class Solution {
public:
    int largestComponentSize(vector<int>& nums) {
        int n = nums.size(), ans = 1;
        unordered_map<int,int> m;
        DSU dsu(100001);
        dsu.init();
        for(auto it:nums)
        {
            for(int i=2;i<=sqrt(it);i++)
            {
                if(it % i == 0)
                {
                    int val1 = dsu.union_set(it, it/i);
                    int val2 = dsu.union_set(it, i);
                }
            }
        }
        for(auto it:nums)
        {
            int par = dsu.find_set(it);
            m[par]++;
        }
        for(auto it:m) ans = max(ans, it.second);
        return ans;
    }
};