//https://practice.geeksforgeeks.org/problems/permutations-of-a-given-string2041/1


class Solution
{
	public:
	
	string swap(string s, int a, int b){
	    char ch = s[b];
	    s[b] = s[a];
	    s[a] = ch;
	    return s;
	}
	
    void solve(string s, int l, int r, vector<string>&res){
        if(l==r){
            res.push_back(s);
            return;
        }
        
        for(int i=l;i<=r;i++){
            s = swap(s, l, i);
            solve(s, l+1, r, res);
            s = swap(s, l ,i);
        }
    }
    
	vector<string>find_permutation(string s)
	{
	    // Code here there
	    vector<string>res;
	    solve(s, 0, s.size()-1, res);
	    
	    sort(res.begin(), res.end());
	    return res;
	}
};