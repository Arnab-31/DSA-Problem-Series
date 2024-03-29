Question: https://leetcode.com/problems/word-ladder/submissions/


Solution: 

static int speedUp=[](){
    std::ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

class Solution {
public:
    
    struct GraphNode 
    {
        string val;
        list <GraphNode *> neigh;
        int distance;
    };
    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList)
    {
        
        unordered_set <string> s;
        bool present = false;
        for(int i=0;i<wordList.size();i++)
        {
             if(endWord.compare(wordList[i])==0)
                 present = true;
             s.insert(wordList[i]);
        }
        
        if(present == false)         //if endword is not present in word List
            return 0;
           
        
        GraphNode* src;
        src = new GraphNode ();
        src -> val = beginWord;
        src -> distance = 1;
        queue <GraphNode *> q;
        q.push(src);                                                                                                                           
        while(!q.empty())
        {
            GraphNode * currNode = q.front();
            q.pop();
            
            string word = currNode->val;
            
            for(int i=0;i<word.size();i++)           //replacing each character with a-z and check if it is present in wordList
            {
                for(int j=97; j<=122; j++)
                {
                    if(word[i] == (char)j)
                        continue;
                    
                    word[i] = (char)j;
                    
                    if(s.find(word) != s.end())        //if present we add it to the graph
                    {
                        GraphNode * newNode = new GraphNode();
                        newNode -> val = word;    
                        currNode -> neigh.push_back(newNode);
                        if(newNode -> val == endWord)
                         return ((currNode -> distance) + 1);                // endNode is reached so return the total distance
                        newNode->distance = currNode -> distance + 1;        //keep increasing the distance everytime to we add a next node
                        q.push(newNode);
                        s.erase(word);
                    }
                    
                    word[i] = currNode -> val[i];
                }
                    
            }
        }
        
        return 0;
        
    }
};