https://leetcode.com/problems/generate-parentheses/

class Solution {
public:
    //据说这里有个漂亮的dp 公式
    // f(n) = '('+ f(i) +')' + f(n-i-1); //做累计
    vector<string> generateParenthesis(int n) {
       vector<string> ans;
        dfs("", n , n , ans);
        return ans;
    }
    
    void dfs(string cur, int left, int right , vector<string>& ans){
        //cur 左侧当前已有的串 
        //left  -> 还可以用几个左括号
        // right -> 还可以用几个右括号
        if(left == 0 && right == 0){
            ans.push_back(cur);
            return ;
        }
        if( left > 0){
            dfs(cur+'(', left -1, right, ans);
        }
        if(right >0 && right > left){
            dfs(cur+')', left, right-1, ans);
        }
    }
};
