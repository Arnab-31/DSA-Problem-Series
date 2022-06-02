//https://leetcode.com/problems/single-threaded-cpu/

//Approach - Store tasks based on sorted time in map and use min heap to find the smallest task every time

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        typedef pair<int, int> pi;
        map<int,vector<pair<int,int>>>mp;
        
        for(int i=0;i<tasks.size();i++){
            mp[tasks[i][0]].push_back({tasks[i][1], i});
        }
        
        int curTime = 0;
        priority_queue<pi, vector<pi>, greater<pi> > pq;
        vector<int>res;
        
        for(auto i:  mp){
            int time = i.first;
            vector<pair<int,int>>taskList = i.second;
            
         
            while(pq.size() > 0 && curTime < time){
                auto a = pq.top();
                curTime += a.first;
                pq.pop();
                res.push_back(a.second);
            }

            if(curTime < time){
                curTime = time;
            }
                
            for(auto j : taskList){
                pq.push({j.first, j.second});
            }
        }
        
        while(!pq.empty()){
            auto a = pq.top();
            res.push_back(a.second);
            pq.pop();
        }
        
        return res;
        
    }
};