https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
     Solution(){
        memset(charCnt,0,sizeof(charCnt));
        memset(target,0,sizeof(target));
    }

    string minWindow(string s, string t) {
        if(s.empty() || t.empty()){
            return "";
        }
        for(auto c :t ){
            target[c]++;
        }

        int minLen = s.size() + 1;//取个大点的值
        int lastIndex = -1;
        int firstTarget = -1;

        //双指针移动， 左指针移动时，需要判断当前char 是否是需要的


        for( int i = 0 ;i < s.size(); i++){
            char x = s[i];
            if( target[x] == 0){
                continue;
            }
            charCnt[x] ++;//
            if( firstTarget == -1){
                firstTarget = i;//第一个字符的位置
            }


            if(isEnough()){
                while(firstTarget< s.size() && firstTarget <= i){
                    mapDec(s[firstTarget++]);
                    if(!isEnough()){
                        int lastLen = i - (firstTarget-1) +1 ;
                        if(minLen > lastLen ){
                            minLen = lastLen ;
                            //因为要输出字符，所以要记录最后一位的位置
                            lastIndex = i;
                         }
                        break;
                    }
                }
                if(minLen == t.size() ){
                    return s.substr(lastIndex- minLen+1 , minLen);
                }
            }
        }
        if(minLen > s.size() || lastIndex < 0 ){
            return "";
        }
        if( minLen < t.size() ){
            return "";
        }
        return s.substr(lastIndex- minLen +1  , minLen);
    }
    void mapDec( char x   ){
         if( charCnt[x] <= 0){
            return ;
        }
        charCnt[x] --;
    }
    //这里的isEnough 还有优化空间， 有重复的计算
    //
    bool isEnough(){
        for( int i = 0 ; i < 257; i++){
            int index = i ;
            if( target[i] <= 0){
                continue;
            }
            if( charCnt[i] <= 0){
                return false;
            }
            if( charCnt[i] < target[i] ){
                return false;
            }
        }
        return true;
    }
    int  charCnt[257];
    int  target[257];
};
