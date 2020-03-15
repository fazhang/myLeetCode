https://leetcode.com/problems/add-binary/

class Solution {
public:

    char charSum(char x, char y, char& carry){
        char out = '0';

        int iout = x + y + carry - '0' - '0' - '0';
        switch(iout){
            case 0:
                out = '0';
                carry = '0' ;
                break;
            case 1:
                out = '1' ;
                carry = '0';
                break;
            case 2:
                out = '0';
                carry = '1';
                break;
            case 3:
                out = '1';
                carry = '1';
        }
        return out;
    }
    string addBinary(string a, string b) {
        int len = max(a.size(), b.size());

        string out(len,'0');

        int blen = b.size() -1;
        int alen = a.size() -1;

        char carry = '0' ;
        for( int i = 0 ; i < len ; i++){
            int bi = blen -i;
            int ai = alen -i ;
            char x ='0';
            char y ='0';
            if( bi >= 0 ){
                y = b[bi];
            }
            if( ai >= 0){
                x = a[ai];
            }

            char sum = charSum(x,y,carry);
            out[len - i -1  ] = sum;
        }
        if( carry == '1'){
            out.insert(out.begin(), '1');
        }
        return out;
    }
};
