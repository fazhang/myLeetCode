https://leetcode.com/problems/plus-one/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> out(digits.size());
        int carry = 1 ;
        for(int i = digits.size()-1; i>=0; i--){
            int sum = digits[i] + carry;
            out[i] = sum%10;
            carry = sum/10;
        }
        if( carry > 0){
            out.insert(out.begin(), carry);
        }
        return out;
    }
};
