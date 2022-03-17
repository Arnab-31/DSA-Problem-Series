
//https://leetcode.com/problems/maximum-number-of-weeks-for-which-you-can-work/

   /*Say the sum is S and maximum element is M. If S >= 2*M, then you can always construct a milestone sequence m1, m2, ......, mS(mi denotes the milestone consumed at the ith step) which would exhaust all the milestones because it possible to consume all of M if the rest i.e (S-M) >= M.
Otherwise, you will always be left with (S-M) milestones at the end of which you can consume only 1.*/

class Solution {
public:
        
     long long numberOfWeeks(vector<int>& mile) 
    {
        long long ans = 0, n = mile.size(), sum = 0; 
        int mx = 0;
        
        for(auto x : mile) {sum += x; mx = max(mx, x);}
        
        if(mx < sum - mx) return sum;
        
        priority_queue<int> pq;
        
        for(auto x : mile) pq.push(x);
        
        while(pq.size() >= 2)
        {
            int x = pq.top(); pq.pop();
            int y = pq.top(); pq.pop();
            
            ans += 2*y;
            
            if(x - y != 0) pq.push(x - y);
        }
        
        if(pq.size()) ans++;
        return ans;
    }

};


//O(n) solution based on same logic



class Solution {
public:
    long long numberOfWeeks(vector<int>& milestones) {
        long long unsigned int maxel = *max_element(milestones.begin(), milestones.end());
        long long unsigned int sum = 0;
        for (auto& m : milestones) sum += m;
        if (sum - maxel >= maxel) return sum;
        return (sum - maxel) * 2 + 1;
    }
};