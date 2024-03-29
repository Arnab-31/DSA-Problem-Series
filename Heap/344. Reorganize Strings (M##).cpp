https://leetcode.com/problems/reorganize-string/

Approach - refer notes
TC = O(nlog26) = O(n)


class Solution {
public:
    string reorganizeString(string s) {
        
        
        int freq[26];
        memset(freq, 0, sizeof freq);
        int max=0,index;
        for(int i=0;i<s.length();i++)
        {
            freq[s[i]-'a']++;
            
            if(freq[s[i] - 'a'] > max)
            {
                max = freq[s[i] - 'a'];
                index = s[i] - 'a';
            }
        }
        
        //check if its possible
        if(s.length() - max < max-1)
            return "";
        else
        {   
            priority_queue<pair<int,int>>h;
            for(int i=0;i<26;i++)
            {
                if(freq[i] != 0)
                {
                    h.push(make_pair(freq[i],i));
                }
            }
            
            int l = h.size();
            pair <int,int> arr[l];
            int j=0;
            string s="";
            while(!h.empty())
            {
                int a  = h.top().first;    //most frequent character
                int b  = h.top().second;
                h.pop();
                
                s = s + (char)(b + 'a');
                
                int c,d;
                if(!h.empty())
                {
                    c  = h.top().first;   //second most frequent character
                    d  = h.top().second;
                    h.pop();
                
                    s = s + (char)(d + 'a');
                }
                
                //push the popped out characters back if they are still left to be used
                if(a!=1)      
                {
                    a = a-1;
                    h.push(make_pair(a,b));
                }
                if(!h.empty() && c!=1)
                {
                    c = c-1;
                    h.push(make_pair(c,d));
                }
            }
        
            return s;
        }
    }
};