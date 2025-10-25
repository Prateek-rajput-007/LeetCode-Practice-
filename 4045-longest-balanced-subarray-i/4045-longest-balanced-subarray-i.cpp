// class Solution {
// public:
//     int longestBalanced(vector<int>& nums) {
//         int n=nums.size();
//         int maxi = INT_MIN;
//         for(int i=0;i<n;i++){
//             unordered_map<int,int> even;
//         unordered_map<int,int> odd;
//             for(int j=i;j<n;j++){
//                 if(nums[j] % 2 == 0){
//                     even[nums[j]]++;
//                 }
//                 else{
//                     odd[nums[j]]++;
//                 }

//                 if(even.size() == odd.size()){
//                     maxi = max(maxi,(j-i+1));
//                 }
//             }
//             if (n - i <= maxi) break;

//         }
//         return maxi;
//     }
// };
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxi = 0;

        for (int i = 0; i < n; i++) {
            unordered_set<int> even, odd;

            for (int j = i; j < n; j++) {
                if (nums[j] % 2 == 0)
                    even.insert(nums[j]);
                else
                    odd.insert(nums[j]);

                if (even.size() == odd.size())
                    maxi = max(maxi, j - i + 1);
            }

            if (n - i <= maxi) break; // small pruning
        }

        return maxi;
    }
};
