#include<string>

class Solution{
    public:
    string findSubString(string str)
    {
        // Your code goes here
        int count = 0;
        bool arr[256] = {false};
        
        //count the number of distict elements
        for(int i=0;i<str.length();i++)
        {
            if(arr[(int)str[i]] == false)
            {
                arr[(int)str[i]] = true;
                count++;
            }
        }
        
        int count2 = 0;
        int arr2[256] = {0};
        int minLen = INT_MAX;
        int start = 0;
        int end;
        for(end= 0;end<str.length();end++)
        {
            //maintain frequency of the characters in the current window
            arr2[str[end]]++;
            
            //if new character came, increase number of distict characters in window
            if(arr2[str[end]] == 1)
                count2++;
            
            //frequency of  first character is more than 1, hence it is not needed so increase i
            while(arr2[(int)str[start]] > 1)
            {
                arr2[(int)str[start]]--;
                start++;
            }
            
            
            //all distinct characters present
            if(count2 == count)
            {
                if(minLen > (end - start + 1))
                    minLen = end - start + 1;
            }
        }
     
   
        return str.substr(start, minLen);
    }
};