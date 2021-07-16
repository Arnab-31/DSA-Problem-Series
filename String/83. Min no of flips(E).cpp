//https://practice.geeksforgeeks.org/problems/min-number-of-flips3210/1

//Aproach - The final string will be either 101010 or 010101, so find no of flips for both the types of string, and return min

//TC-O(N)


int minFlips (string s)
{
    // your code here
    int flip1 = 0, flip2 = 0;
    for(int i = 0; i<s.length();i++)
    {
        if(i%2 == 0 && s[i] == '0')
            flip1++;
        else if(i%2 != 0 && s[i] == '1')
            flip1++;
    }
    
    for(int i = 0; i<s.length();i++)
    {
        if(i%2 == 0 && s[i] == '1')
            flip2++;
        else if(i%2 != 0 && s[i] == '0')
            flip2++;
    }
    
    return min(flip1, flip2);
}