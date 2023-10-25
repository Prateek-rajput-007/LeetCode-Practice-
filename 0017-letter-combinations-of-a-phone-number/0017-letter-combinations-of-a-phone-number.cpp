class Solution {
public:
    void solve(string digit,string output,int index,vector<string>&mp,vector<string>&ans){
        if(index>=digit.length()){
            ans.push_back(output);
            return;
        }
        int num=digit[index]-'0';
        string value= mp[num];
        for(int i=0;i<value.length();i++){
            output.push_back(value[i]);
            solve(digit,output,index+1,mp,ans);
            output.pop_back();
        }

}
    vector<string> letterCombinations(string digits) {
        vector<string>mp(10);
        vector<string>result;
        if(digits.length()==0){
            return result;
        }
        string output;
        mp[2]="abc";
        mp[3]="def";
        mp[4]="ghi";
        mp[5]="jkl";
        mp[6]="mno";
        mp[7]="pqrs";
        mp[8]="tuv";
        mp[9]="wxyz";
        int start=0;
        solve(digits,output,start,mp,result);
        return result;
    }
};