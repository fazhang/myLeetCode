https://leetcode.com/problems/longest-common-prefix/

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.empty()){
            return "";
        }
         string str0 = strs[0];
        if(strs.size() == 1 ){
            return str0;
        }

        for( int i = 0 ; i < str0.size(); i++){
            char x = str0[i];
            for(int j = 1; j< strs.size(); j++){
                char y = strs[j][i];//第j个string 的第i 位
                if( y != x){
                    return str0.substr(0,i);
                }
            }
        }
        return str0;
    }
};
