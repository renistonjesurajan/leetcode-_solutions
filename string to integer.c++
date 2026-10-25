
#include <iostream>
#include <string>
#include <climits>
#include <cctype>
using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
        long long num = 0;
        int sign = 1;

        // Skip leading spaces
        while (i < n && s[i] == ' ') {
            i++;
        }

        // Check sign
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-') {
                sign = -1;
            }
            i++;
        }

        // Convert digits to integer
        while (i < n && isdigit((unsigned char)s[i])) {
            num = num * 10 + (s[i] - '0');

            if (sign * num >= INT_MAX) {
                if (sign == 1 && num > INT_MAX)
                    return INT_MAX;
            }

            if (sign * num < INT_MIN)
                return INT_MIN;

            i++;
        }

        return (int)(sign * num);
    }
};
