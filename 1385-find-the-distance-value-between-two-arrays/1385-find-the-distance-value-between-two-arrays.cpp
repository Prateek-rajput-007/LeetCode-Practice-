class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        sort(arr2.begin(), arr2.end());

        int ans = 0;

        for (int i = 0; i < arr1.size(); i++) {
            int num = arr1[i];
            int lower = num - d, upper = num + d;
            int beg = 0, end = arr2.size() - 1;

            while (beg <= end) {
                int mid = (beg + end) / 2;

                if (arr2[mid] < lower)
                    beg = mid + 1;
                else if (arr2[mid] > upper)
                    end = mid - 1;
                else
                    break;
            }

            if (end < beg)
                ans++;
        }

        return ans;
    }
};