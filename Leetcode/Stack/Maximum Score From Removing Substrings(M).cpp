//https://leetcode.com/contest/biweekly-contest-43/problems/maximum-score-from-removing-substrings/

class Solution {
public:
    
    int solve(string &s, string sub, int points){
        
        stack<char>st;
        st.push(s[0]);
        int p = 0;
        for(int i=1;i<s.length(); i++){
            
            if(!st.empty()){
                char c1 = st.top();
                char c2 = s[i];
                string a = "";
                a += c1;
                a += c2;
                if(a == sub){
                    p += points;
                    st.pop();
                    //cout<<i<<sub<<endl;
                }else
                    st.push(c2);
            }else{
                st.push(s[i]);
            }
        }
        
        string s2 = "";
        while(!st.empty()){
            char c = st.top();
            st.pop();
            s2 += c;
        }
        reverse(s2.begin(), s2.end());
        s = s2;
        return p;
    }
    
    int maximumGain(string s, int x, int y) {
        string a,b;
        if(x > y){
            a = "ab";
            b = "ba";
        }else{
            b = "ab";
            a = "ba";           
        }
        
        int p = a == "ab" ? x : y;
        int q = p == x ? y : x;
        
        int n = solve(s, a, p);
        int m = solve(s, b, q);
        
        return n + m;
   }
};