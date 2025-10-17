class Solution {
public:
    int getcount(vector<int>& a)
    {
        int count=0,set=0;
        for(int i=0;i<a.size();i++)
        {
            if(set)
            {
                count+=2*a[i];
                set--;
            }
            else
            {
                count+=a[i];
            }
            if(a[i]==10)
            set=2;
        }
        return count;

    }

    int isWinner(vector<int>& player1, vector<int>& player2) 
    {
        int first=getcount(player1);
        int second=getcount(player2);
        return first == second ? 0 : (first<second) + 1 ;  
    }
};