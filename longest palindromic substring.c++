#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0;
        int maxLength = 0;

        for (int center = 0; center < static_cast<int>(s.size()); ++center) {
            expandFromCenter(s, center, center, start, maxLength);     // Odd length
            expandFromCenter(s, center, center + 1, start, maxLength); // Even length
        }

        return s.substr(start, maxLength);
    }

private:
    void expandFromCenter(const string& s, int left, int right,
                          int& start, int& maxLength) {
        while (left >= 0 &&
               right < static_cast<int>(s.size()) &&
               s[left] == s[right]) {
            --left;
            ++right;
        }

        int length = right - left - 1;
        if (length > maxLength) {
            start = left + 1;
            maxLength = length;
        }
    }
};
