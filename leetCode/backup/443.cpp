https://leetcode.com/problems/string-compression/

class Solution {
public:
    int compress(vector<char>& chars) {
        if( chars.empty()){
            return 0;
        }
        int inputLen = chars.size();
        int outLen = 0;

        int cur = 0 ;   //当前读到哪个字符
        int last = -1 ;  //上一次写数值的地方
        int ret = 0 ;   //返回总长度

        while( cur < inputLen){
            char x = chars[cur];
            int cnt = 1;// x 的计数器 至少1个
            if( cur == inputLen -1){
                chars[++last] = x;
               // ret = last+1;
                break;
            }
            int curnext = cur+1;
            while ( curnext < inputLen && chars[curnext] == x ){
                cnt++;
                curnext++;
            }

            chars[++last] = x;
            //last++;
            if( cnt > 1){

                //这里要考虑cnt > 10 的场景
                int tmpcnt = cnt;
                stack<int> tmpstack;
                while (tmpcnt > 0){
                    int n = tmpcnt%10;
                    tmpcnt /= 10;
                    tmpstack.push(n);
                }
                while(!tmpstack.empty()){
                    chars[++last] = '0'+ tmpstack.top();
                    tmpstack.pop();
                }
            }
            cur += cnt;
        }
        return last+1;
    }
};
