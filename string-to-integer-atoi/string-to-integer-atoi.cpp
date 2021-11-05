class Solution {
public:
    int myAtoi(string s) {
        size_t i = 0;
        while (s[i] == ' ') {
            i++;
        }
        int sign = 1;
        if (s[i] == '-') {
            sign = -1;
            i++;
        } 
        else if (s[i] == '+') {
            i++;
        }
        int ans = 0;
        while (i != s.size()) {
            if (s[i] > '9' || s[i] < '0') {
                break;
            }

            int dig = (s[i] - '0') * sign;
            if (sign == 1) 
            {
                if (ans > INT_MAX / 10 || (ans == INT_MAX / 10 && dig > INT_MAX % 10)) {
                    return INT_MAX;
                }
            } 
            else 
            {
                if (ans < INT_MIN / 10 || (ans == INT_MIN / 10 && dig < INT_MIN % 10)) {
                    return INT_MIN;
                }
            }
            ans = ans * 10 + dig;
            i++;
        }
        return ans;
    }
};