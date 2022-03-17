//https://leetcode.com/problems/longest-arithmetic-subsequence/



//Similar to LIS
//dif[i][j] means max length of subsequence ending at index i having a constant difference of j


class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {

        
        int dif[nums.size()][1001];
    
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<=1000;j++){
                dif[i][j] = j == 500 ? 1 : 0; 
            }
        }
        
        int ans = 1;
        for(int i=1;i<nums.size();i++){
            for(int j=0;j<i;j++){
                
                int curDif = nums[i] - nums[j] +  500;
                dif[i][curDif] = dif[j][curDif] == 0 ? 2 : 1 +  dif[j][curDif];
                ans = max( ans,  dif[i][curDif]);
            }
        }
         
        return ans;
    }
};