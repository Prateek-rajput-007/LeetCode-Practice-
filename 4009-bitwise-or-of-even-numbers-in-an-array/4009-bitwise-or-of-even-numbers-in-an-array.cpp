class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int bitOr=0;
        for(int num:nums){
            if(num%2==0){
                bitOr|=num;
            }
        }
        return bitOr;
    }
};