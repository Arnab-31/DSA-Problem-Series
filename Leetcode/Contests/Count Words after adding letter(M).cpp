//https://leetcode.com/problems/count-words-obtained-after-adding-a-letter/


//https://www.youtube.com/watch?v=sOwnyBgtqPw&ab_channel=CodeScience

class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<string> st;
        for(auto s:startWords){
            sort(s.begin(),s.end());
            st.insert(s);
        }
        int ans = 0;
        for(auto s:targetWords){
            sort(s.begin(),s.end());
            int n = s.length();
            for(int i = 0;i<n;i++){
                if( st.find(s.substr(0,i)  +  s.substr(i+1,n-i-1)) != st.end()){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};