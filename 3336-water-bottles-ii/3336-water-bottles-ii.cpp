class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int drink = numBottles;
        
        int emptyBottles = drink;
        
        while(emptyBottles >= numExchange) {
            
            emptyBottles -= numExchange;
            
            drink++;
            
            numExchange++;
            
            if(emptyBottles == 0)
                break;
            
            emptyBottles++;
        }
        
        return drink;
    }
};