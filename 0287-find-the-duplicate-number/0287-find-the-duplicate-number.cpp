// class Solution {
// public:
//     int findDuplicate(vector<int>& nums) {
//         while(nums[0]!=nums[nums[0]])
//         {
//             swap(nums[0],nums[nums[0]]);
//         }
//         return nums[0];
//     }
// };
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        int fast = nums[0];
        int slow = nums[0];
        
        do{
            fast = nums[nums[fast]];
            slow = nums[slow];
        }while(fast != slow);
        
        fast = nums[0];
        
        while(fast != slow)
        {
            fast = nums[fast];
            slow = nums[slow];
        }
        
        return slow;
        
    }
};