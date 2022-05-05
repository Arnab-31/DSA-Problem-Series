//https://practice.geeksforgeeks.org/problems/word-break1352/1

class Solution
{
public:

    int solve(string A, string cur, int id, unordered_set<string>st){
    
        
        if(st.find(cur) != st.end()){
            if(id == A.length()){
                return 1;   
            }else{
                if(solve(A, "", id, st) ||  solve(A, cur + A[id], id + 1, st))
                    return 1;
                else
                    return 0;
            }
        }
        
        if(id == A.length())
            return 0;
            
        return solve(A, cur + A[id], id+1, st);
    }
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        unordered_set<string>st;
        for(auto i : B)
            st.insert(i);
        
        int ans = solve(A, "" , 0, st);
        
        return ans;
    }
};

