#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1 || numRows >= static_cast<int>(s.size())) {
            return s;
        }

        vector<string> rows(numRows);
        int row = 0;
        int direction = 1; // 1 = down, -1 = up

        for (char c : s) {
            rows[row] += c;

            if (row == 0) {
                direction = 1;
            } else if (row == numRows - 1) {
                direction = -1;
            }

            row += direction;
        }

        string result;
        for (const string& currentRow : rows) {
            result += currentRow;
        }

        return result;
    }
};
