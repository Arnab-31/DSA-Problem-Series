//https://practice.geeksforgeeks.org/problems/isomorphic-strings-1587115620/1

class Solution
{
    public:
    //Function to check if two strings are isomorphic.
    bool areIsomorphic(string str1, string str2)
    {
        
        // Your code here
        char arr1[256];
        char arr2[256];
        memset(arr1, '#', sizeof(arr1));
         memset(arr2, '#', sizeof(arr2));
        
        if(str1.length() != str2.length())
            return false;
            
        for(int i = 0;i<str1.length();i++)
        {
            if(arr1[(int)str1[i]] == '#' && arr2[(int)str2[i]] == '#')
            {
                arr1[(int)str1[i]] = str2[i];
                arr2[(int)str2[i]] = str1[i];
            }
            else
            {
                if(arr1[(int)str1[i]] != str2[i] || arr2[(int)str2[i]] != str1[i])
                {
                    return false;
                }
            }
        }
        
        return true;
        
    }
};