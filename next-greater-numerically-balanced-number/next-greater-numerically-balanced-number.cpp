class Solution {
public:
    bool check(int n)
    {
        vector<int> freq(10,0);
        while(n)
        {
            int x = n%10;
            freq[x]++;
            n /= 10;
        }
        for(int i=0; i<10; i++)
            if(freq[i] and freq[i]!=i) return false;
        return true;
    }
    
    int nextBeautifulNumber(int n) {
        while(true) 
        {
            n++;
            if(check(n)) return n;
        }
        return 1;
    }
};