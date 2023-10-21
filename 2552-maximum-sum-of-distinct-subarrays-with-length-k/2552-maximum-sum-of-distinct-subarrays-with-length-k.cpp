class Solution {
public:
    long long maximumSubarraySum(vector<int>& arr, int k) {
        int i = 0;
        int j = 0;
        int n = arr.size();
        long long sum = 0;
        long long maxi = 0; // Initialize to the minimum value of long long
        
        map<int, int> mpp;

        while (j < n) {
            mpp[arr[j]]++;
            sum += arr[j];

            if (j - i + 1 < k) {
                j++;
            } 
            else if (j - i + 1 == k) {
                
                if(mpp.size()==k){
                maxi=max(maxi,sum);
                }

                mpp[arr[i]]--;

                if(mpp[arr[i]]==0) mpp.erase(arr[i]);
                sum-=arr[i];
                i++;
                j++;
            }
        }

        return maxi;
    }
};