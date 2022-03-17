//https://leetcode.com/problems/bitwise-ors-of-subarrays/

//Aproach - https://leetcode.com/problems/bitwise-ors-of-subarrays/discuss/165859/C%2B%2B-O(kN)-solution


class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        unordered_set<int> s;
        unordered_set<int> t;
        for (int i : A) {
            unordered_set<int> r;
            r.insert(i);
            for (int j : t) r.insert(i | j);
            t = r;
            for (int j : t) s.insert(j);
        }
        return s.size();
    }
};