class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int i, j=0;
        vector<string> ans;
        for(i=1 ; i<=n ; i++)
        {
            if(target[j]==i)
            {
                ans.push_back("Push");
                j++;
                if(j==target.size())
                    break;
            }
            else
            {
                ans.push_back("Push");
                ans.push_back("Pop");
            }
        }
        return ans;
    }
};