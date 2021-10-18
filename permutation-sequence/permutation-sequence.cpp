class Solution {
public:
    int findFirstNumIndex(int& k, int n)
    {
        if(n == 1) return 0;
        n--;
        int first_num_index;
        int n_partial_fact = n;
        while (k >= n_partial_fact and n > 1) {
            n_partial_fact = n_partial_fact * (n - 1);
            n--;
        }
        first_num_index = k / n_partial_fact;
        k = k % n_partial_fact;
        return first_num_index;
    }

    string getPermutation(int n, int k) {
        string ans = "";
        set<int> s;
        for (int i = 1; i <= n; i++)
            s.insert(i);
        set<int>::iterator itr;
        itr = s.begin();
        k = k - 1;
        for (int i = 0; i < n; i++) 
        {
            int index = findFirstNumIndex(k, n - i);
            advance(itr, index);
            ans += (to_string(*itr));
            s.erase(itr);
            itr = s.begin();
        }
        return ans;
    }
};