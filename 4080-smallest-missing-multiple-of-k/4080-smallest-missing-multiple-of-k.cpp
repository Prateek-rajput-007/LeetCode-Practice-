class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size(), ans=0, j=k;
        set<int> st;
        int g=1;
        for(auto i: nums){
            st.insert(i);
        }
        for(int i=0;i<=n;i++){
            int a = j*g;
            if(st.find(a)==st.end()){
                ans=a;
                break;
            }
            g++;
        }
    return ans;
    }
};