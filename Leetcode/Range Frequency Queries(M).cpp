//https://leetcode.com/problems/range-frequency-queries/


class RangeFreqQuery {
public:
    vector<int>a;
    unordered_map<int,vector<int>>v;
    
    RangeFreqQuery(vector<int>& arr) {
        
        a = arr;
        
        for(int i =0;i<arr.size();i++){
            v[arr[i]].push_back(i);
        }
    }
    
    int query(int left, int right, int value) {
        int l = lower_bound(v[value].begin(), v[value].end(), left) - v[value].begin();
        int u = upper_bound(v[value].begin(), v[value].end(), right) - v[value].begin();
        
        //cout<<u<<" "<<l<<endl;
        return u - l;
        
        
    }
};


