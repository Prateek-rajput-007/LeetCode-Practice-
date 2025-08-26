class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int maxDiagonalSq = 0;
        int maxArea = 0;

        for (int i = 0; i < dimensions.size(); ++i) {
            int length = dimensions[i][0];
            int width = dimensions[i][1];
            int area = length * width;
            int diagonalSq = length * length + width * width;

            if (diagonalSq > maxDiagonalSq) {
                maxDiagonalSq = diagonalSq;
                maxArea = area;
            } else if (diagonalSq == maxDiagonalSq) {
                maxArea = max( maxArea,area);
            }
        }

        return maxArea;
    }
};