class Solution {
public:
    bool checkValidString(string s) 
    {
        int left=0,star=0,right=0,i,n=s.size();
        for(i=0;i<n;i++){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;
            else if(s[i]=='*') star++;
            if(left+star<right) return 0;
        }
        left=0; star=0; right=0;
        for(i=n-1;i>=0;i--){
            if(s[i]=='(') left++;
            else if(s[i]==')') right++;
            else if(s[i]=='*') star++;
            if(right+star<left) return 0;
        }
        return 1;
    }
};