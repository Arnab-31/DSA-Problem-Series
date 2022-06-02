//https://practice.geeksforgeeks.org/problems/wildcard-string-matching1126/1#

//Aproach - Brute Force. It can be furhter memoized. 


class Solution{
    public:
    
    bool solve(string wild, string pattern, int id1, int id2){
        
 
        if(id1 == wild.length() && id2 == pattern.length()){
            return true;    
        }else if(id1 >= wild.length())
            return false;
        else if(id2 == pattern.length()){
           
            if(wild[id1] == '*'){
                return solve(wild, pattern, id1+1, id2);
            }
            else{
               
                return false;
            }
        }
        
        if(wild[id1] != pattern[id2]){
            if(wild[id1] == '?')
                return solve(wild, pattern, id1+1, id2+1);
            else if(wild[id1] == '*'){
                for(int i = id2;i<=pattern.length();i++){
                    if(solve(wild, pattern, id1+1, i))
                        return true;
                }
                
                return false;
            }else
                return false;
        }else
            return solve(wild, pattern, id1+1, id2+1);
    }
    
    bool match(string wild, string pattern)
    {
        // code here
        return solve(wild, pattern, 0, 0);
    }
};