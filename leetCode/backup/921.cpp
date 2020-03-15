https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/

class Solution {
public:
    int minAddToMakeValid(string S) {
         int len = S.length();
    int first = 0,last = 0; //first记录反括号数量，last记录括号数量
    for(int i=0;i<len;i++){
        if(S[i]=='('){
            last++;
        }
        else {
            if(last==0){
                first++;
            }
            else {
                last--;
            }
        }
    }
    return first+last;
//https://blog.csdn.net/lwgkzl/article/details/83151765
    }
};
