https://leetcode.com/problems/task-scheduler/

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto t : tasks){
            mp[t]++;
        }
        
        priority_queue<pair<int,char>>pq;
        for(auto i : mp){
            pq.push({i.second, i.first});
        }
        
        int totalTime = 0;
        while(!pq.empty()){
            
            int t = 0;
            stack<pair<int,char>>v;
            
            //perform n+1 sec cycle of tasks or till tasks are left , whichever is earlier.
            while(t <= n && !pq.empty()){
                auto i = pq.top();
                v.push({i.first-1, i.second});
                pq.pop();
                t++;
            }
            
            totalTime += t;
            
            //add back those tasks which needs to be performed again
            while(!v.empty()){
                if(v.top().first !=0) pq.push(v.top());
                v.pop();
            }
            
            //if more tasks are still left, then we have to complete the time cycle of n+1 sec before starting the next task
            if(!pq.empty() && t <= n+1) totalTime += n-t+1;
        }
        
        return totalTime;
    }
};