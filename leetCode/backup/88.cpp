https://leetcode.com/problems/merge-sorted-array/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int last = m+n -1;

        while( m > 0 && n > 0){
            int t = nums1[m-1];
            int s = nums2[n-1];

            if( s >=t ){
                nums1[last] = s;
                n--;
            }else{
                nums1[last] = t;
                m--;
            }
            last--;
        }
        if( m > 0 ){
            return;
        }
        while( n > 0){
            nums1[n-1] = nums2[n-1];
            n--;
        }

    }
};
