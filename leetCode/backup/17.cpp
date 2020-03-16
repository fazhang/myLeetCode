https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
public:
    Solution(){
        digit2Char['1'] = {};
        digit2Char['2'] = {'a','b','c'};
        digit2Char['3'] = {'d','e','f'};
        digit2Char['4'] = {'g','h','i'};
        digit2Char['5'] = {'j','k','l'};
        digit2Char['6'] = {'m','n','o'};
        digit2Char['7'] = {'p','q','r','s'};
        digit2Char['8'] = {'t','u','v'};
        digit2Char['9'] = {'w','x','y','z'};
        digit2Char['0'] = {' '};
    }
    vector<string> letterCombinations(string digits) {
        vector<string> tmp ;
        vector<string> tmp2 ;
        if( digits.size() > 1){
            tmp2 = letterCombinations(digits.substr(1,digits.size() -1));
        }
        vector<char>& td = digit2Char[digits[0]];
        for( auto c : td){
            if( tmp2.empty()){
                tmp.push_back(string("") + c );
            }else{
                for( auto i : tmp2){
                    tmp.push_back( c + i);
                }
            }
        }
        return tmp;
    }

    map<char, vector<char> > digit2Char;
};
