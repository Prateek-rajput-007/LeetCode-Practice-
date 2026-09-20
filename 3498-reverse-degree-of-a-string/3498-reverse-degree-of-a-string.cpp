class Solution {
public:
    int reverseDegree(string s) {
        int val = 0;

        for(int i=0;i<s.size();i++){
            int index_product = ('z'-s[i]+1)*(i+1);
            val+=index_product;
        }

        return val;
    }
};