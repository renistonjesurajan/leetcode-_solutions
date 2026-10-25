#include <algorithm>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> lastSeen;
        int left = 0;
        int longest = 0;

        for (int right = 0; right < s.size(); ++right) {
            char current = s[right];

            if (lastSeen.count(current) && lastSeen[current] >= left) {
                left = lastSeen[current] + 1;
            }

            lastSeen[current] = right;
            longest = max(longest, right - left + 1);
        }

        return longest;
    }
};
