//https://practice.geeksforgeeks.org/problems/print-anagrams-together/1#


//Approach -  Create a string hash to represnt every string based on its characters. Use the hash to group all anagrams.

class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& strl) {
        //code here
        
        unordered_map<string, vector<string>>mp;
        for(auto s : strl){
            string hash = "00000000000000000000000000";
            for(char c : s){
                int id = c - 'a';
                int cur = hash[id] - '0';
                cur++;
                char nchar = cur + '0';
                hash[id] = nchar;
            }
            
            mp[hash].push_back(s);
        }
        
        vector<vector<string>>ans;
        for(auto v : mp){
            auto vec = v.second;
            //sort(vec.begin(), vec.end());
            ans.push_back(vec);
        }
        
        return ans;
    }
};