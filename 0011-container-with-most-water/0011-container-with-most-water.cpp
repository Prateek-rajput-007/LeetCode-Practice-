class Solution {
public:
    int maxArea(vector<int>& height) {

        int ans = 0;
        int s = 0;
        int e = height.size() - 1;
        int w=0,h=0,area=0;
        while(s < e) {
            w = e-s;
            h = min(height[s],height[e]);
            area = w*h;
            ans = max(ans,area);
            if(height[s] < height[e])
                s++;
            else 
                e--;
        }

        return ans;
        
    }
};