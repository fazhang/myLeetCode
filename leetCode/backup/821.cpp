https://leetcode.com/problems/shortest-distance-to-a-character/

class Solution {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<int> result(S.size());
        if(S.empty()){
            return result;
        }

       // vector<int> char2Index(257,-1);

        int firstIndex = -1;

        for( int i = 0 ; i < S.size(); i++){
            if(S[i] == C){
                firstIndex = i ;
                break;//找到第一个位置
            }
        }
        for( int i = 0 ; i < firstIndex; i++){
            result[i] = firstIndex - i ; //初始化前一段
        }
        int lastS = firstIndex;

        //需要初始化两个位置
        for(int i = firstIndex+1 ; i < S.size(); i++){
            char x = S[i];

            if( x != C){
                result[i] = i - lastS;
                //if这个分支可以优化掉
            }else{
                result[i] = 0;// 更新为0
                //如果又碰到一个C 字符
               //那么 [(lastS +i +1)/2 , curIndex] 需要更新，只追溯这一半即可
                for( int j = i-1 ; j >= (lastS + i + 1 )/2 ; j --  ){
                    result[j] =  i - j ;
                }
                lastS = i;
            }
        }
        return result;
    }
};
