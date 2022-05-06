//https://practice.geeksforgeeks.org/problems/minimum-characters-to-be-added-at-front-to-make-string-palindrome/1/

//Approach - Use the LPS array used in KMP algo. Check notes details.


class Solution {
public:
    int minChar(string s){
        //Write your code here
        string a = s;
        reverse(a.begin(), a.end());
        int len = s.length();
        
        s = s + '$';
        s += a;
        
        
        int arr[s.length()];
        arr[0] = 0;
        
        int i=0,j=1;
        
        while(j < s.length()){
            if(s[i] == s[j]){
                arr[j] = i+1;
                i++;
                j++;
            }else{
                if(i == 0){
                    arr[j] = 0;
                    j++;
                }else{
                    i = arr[i-1];
                }
            }
        }
        
        int x = arr[s.length()-1];
        
        return len - x;
    }
};
