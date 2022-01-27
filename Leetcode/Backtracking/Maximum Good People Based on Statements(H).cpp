//https://leetcode.com/contest/weekly-contest-277/problems/maximum-good-people-based-on-statements/

//Was trying to solve it through graph, but it can be solved by bruteforce by backtracking
//A person can either be good or bad.
//However, we cant be sure & assigning a person as good cant lead to contradictions in statements
//We explore both possibilities of a person being good or bad
//Finally, we check if current configuration is valid or not

class Solution {
public:
    int ans = 0;
    
    int maximumGood(vector<vector<int>>& st) {
        
        string cur = "";
        int cnt  =  0;
        int idx = 0;
    
        dfs(st, idx, cur, cnt);
        return ans;
    }
    
    
    void dfs(vector<vector<int>>& st , int idx, string cur, int cnt){
        
        
        if(idx == st.size()){
            
            if(isValid(st, cur))
                ans = max(ans, cnt);
            return;
        }
        
        dfs(st, idx + 1, cur + "1", cnt + 1);
        dfs(st, idx + 1, cur + "0", cnt);
        
    }
    
    bool isValid(vector<vector<int>>& st, string cur){
        
        for(int i=0;i<cur.length();i++){
            
            char a = cur[i]; 
            for(int j = 0;j<st.size();j++){
                if(a == '0' && (cur[j] == '1' && st[j][i] == 1))
                    return false;
                
                if(a == '1' && (cur[j] == '1' && st[j][i] == 0))
                    return false;  
            }
        }
        
        
        return true;
    } 
};