https://leetcode.com/problems/next-greater-element-i/

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

        int len1 = nums1.size();
        int len2 = nums2.size();

        stack<int>  s;
        vector<int>  ret(len1,-1);
        vector<int>  nextEle(len2,-1);
        map<int,int> val2index;


         for( int i = 0 ; i < len2;  ){
            int x = nums2[i];
             val2index[x] = i;
            if(s.empty()){
                s.push(i);//推当前的下标进去
                i++;
                continue;
            }
            if( x > nums2[s.top()]){
                nextEle[s.top()] = x;
                s.pop();
            }else{
                s.push(i);
                i++;
            }
        }

        for( int i = 0 ; i < nums1.size(); i++){
            int index = val2index[nums1[i]];
            ret[i] = nextEle[index];
        }
        return ret;
    }
};
