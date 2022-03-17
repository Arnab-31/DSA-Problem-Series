//https://leetcode.com/problems/minimum-moves-to-reach-target-score/

class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        
        int c = 0 ;
        
        if(maxDoubles == 0)
            return target-1;
        
        while(target > 1){
            
            if(maxDoubles == 0){
                c += target - 1;
                break;
            }
            
            if(target % 2 == 0 && maxDoubles > 0){
                target /= 2;
                maxDoubles--;
            }
            else
                target -= 1;

            c++;
        }
        
        return c;
        
        
        
    }
};