https://leetcode.com/problems/excel-sheet-column-title/

class Solution {
public:
    string convertToTitle(int n) {

         string res;
        while (n != 0) {
            int temp = n%26;

            if (temp == 0) {
                n-=26;
                temp = 26;
            }
            res.insert(res.begin(), char(temp + 'A' - 1));
            n/=26;
        }
        return res;

    }
};
