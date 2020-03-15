https://leetcode.com/problems/pascals-triangle/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int > > out(numRows,{1});
        if( numRows > 0){
            out[0].resize(1);
           out[0][0] = 1;
        }
        if( numRows > 1){
            out[1].resize(2);
            out[1][0] = 1;
            out[1][1] = 1;
        }
        for(int i = 2 ; i < numRows;i++){
            vector<int>& local = out[i];//取个引用
            local.resize(i+1);
            vector<int>& last = out[i-1];
            local[0] = 1;
            local[i] = 1;
            for( int j = 1; j < i  ; j++){
                local[j] = last[j-1] + last[j];
            }
        }
        return out;
    }
};
