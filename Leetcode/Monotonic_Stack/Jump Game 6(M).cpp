
//https://leetcode.com/problems/jump-game-vi/submissions/

//Explanation - https://www.youtube.com/watch?v=W8N8EeWDwKs&ab_channel=Fraz

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        int dp[n];
        dp[n-1] = nums[n-1];
        deque<int>q;
        q.push_front(n-1);
        
        for(int i=n-2;i>=0;i--){
        
            if(q.front() - i > k) q.pop_front();
            dp[i] = nums[i] + dp[q.front()];
            while(!q.empty() && dp[q.back()]< dp[i])
                q.pop_back();
            q.push_back(i);
        }
        
        return dp[0];
    }
};