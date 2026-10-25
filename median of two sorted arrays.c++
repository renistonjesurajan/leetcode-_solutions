#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        // Binary-search the shorter array.
        if (nums1.size() > nums2.size()) {
            return findMedianSortedArrays(nums2, nums1);
        }

        int m = nums1.size();
        int n = nums2.size();
        int half = (m + n + 1) / 2;

        int low = 0;
        int high = m;

        while (low <= high) {
            int i = low + (high - low) / 2; // Partition in nums1
            int j = half - i;               // Partition in nums2

            long long leftA  = (i == 0) ? LLONG_MIN : nums1[i - 1];
            long long rightA = (i == m) ? LLONG_MAX : nums1[i];
            long long leftB  = (j == 0) ? LLONG_MIN : nums2[j - 1];
            long long rightB = (j == n) ? LLONG_MAX : nums2[j];

            if (leftA <= rightB && leftB <= rightA) {
                long long leftMax = max(leftA, leftB);

                if ((m + n) % 2 == 1) {
                    return static_cast<double>(leftMax);
                }

                long long rightMin = min(rightA, rightB);
                return (static_cast<double>(leftMax) + rightMin) / 2.0;
            }

            if (leftA > rightB) {
                high = i - 1; // Partition in nums1 is too far right
            } else {
                low = i + 1;  // Partition in nums1 is too far left
            }
        }

        return 0.0; // Inputs are sorted, so a valid partition will be found.
    }
};
