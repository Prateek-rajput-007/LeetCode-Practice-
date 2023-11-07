class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int i=num.size()-1;
        vector<int> ans;
        int carry=0;
        while(i>=0 || k!=0 || carry){
            int sum=0;
            if(i>=0){
                sum+=num[i];
                i--;
            }
            if(k!=0){
                sum+=(k%10);
                k=k/10;
            }
            sum+=carry;
            carry=sum/10;
            ans.push_back(sum%10);

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};