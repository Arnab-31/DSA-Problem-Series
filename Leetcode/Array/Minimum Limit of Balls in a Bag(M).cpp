//https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/

//Appraoch -  Bin search in answer

class Solution {
public:
    
    bool isPossible (vector<int>& nums, int op, int m){
        for(auto i  :  nums) {
            int x = i/m;  //No of bags with at most m balls. Those many times we have to divide, coz every division creates one extra ball than previouss.
            if(i%m == 0)  //If it is divisble , then we take all the bags including the orginal bag for which we dont need to divide, so we subtract one bag
                x -= 1;
            op -= x; //  
        }
        
        return op >= 0;
    } 
    
    int minimumSize(vector<int>& nums, int op) {
       int r = INT_MIN;
        
        for(auto i : nums)
            r = max(r, i);
        
        int l = 1;
        int ans;
        while(l <= r){
            int m = l + (r-l)/2;
            
            if(isPossible(nums, op, m)){
                ans = m;
                r = m-1;
            }else{
                l = m+1;
            }
        }
        
        return ans;
    }
};

