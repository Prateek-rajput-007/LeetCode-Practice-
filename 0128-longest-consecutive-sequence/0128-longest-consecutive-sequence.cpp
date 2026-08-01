class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0) return 0;
        
        int longest = 1;
        unordered_set<int> st;

        for(int i : nums){
            st.insert(i);
        }

        for(auto i : st){
            if(st.find(i - 1) == st.end()){
                int count = 1;
                int x = i;

                while(st.find(x + 1) != st.end()){
                    x++;
                    count++;
                }

                longest = max(longest, count);
            }
        }

        return longest;
    }
};