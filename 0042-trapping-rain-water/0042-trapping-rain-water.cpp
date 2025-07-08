class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        int leftmax = 0, rightmax = 0, water = 0, index = 0;
        int maxheight = arr[0];
        for (int i = 1; i < n; i++) {
            if (maxheight < arr[i]) {
                maxheight = arr[i];
                index = i;
            }
        }
        // left part
        for (int i = 0; i < index; i++) {
            if (leftmax > arr[i]) {
                water += (leftmax - arr[i]);
            } else {
                leftmax = arr[i];
            }
        }
        // right part
        for (int i = n - 1; i >= index; i--) {
            if (rightmax > arr[i]) {
                water += (rightmax - arr[i]);
            } else {
                rightmax = arr[i];
            }
        }
        return water;
    }
};