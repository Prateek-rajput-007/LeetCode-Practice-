class Solution {
public:
    void mergeSort(vector<int>&nums,int l,int h){
        if(l>=h){
            return;
        }
        int mid=(l+h)/2;
        mergeSort(nums,l,mid);
        mergeSort(nums,mid+1,h);
        merge(nums,l,mid,h);
    }
    void merge(vector<int>&nums,int l,int mid,int h){
        vector<int>temp;
        int left=l;
        int right=mid+1;
        while(left<=mid && right<=h){
            if(nums[left]<=nums[right]){
                temp.push_back(nums[left]);
                left++;
            }else{
                temp.push_back(nums[right]);
                right++;
            }
        }
        while(left<=mid){
            temp.push_back(nums[left]);
            left++;
        }
        while(right<=h){
            temp.push_back(nums[right]);
            right++;
        }
        for(int i=l;i<=h;i++){
            nums[i]=temp[i-l];
        }
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        mergeSort(nums,low,high);
        return nums;
    }
};