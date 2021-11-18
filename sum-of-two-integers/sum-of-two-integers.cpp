class Solution {
public:
    int getSum(int x, int y) {
        while (y != 0)
        {
            unsigned carry = x & y;
            x ^= y;
            y = carry << 1;
        }
        return x;
    }
};