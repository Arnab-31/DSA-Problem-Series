https://practice.geeksforgeeks.org/problems/longest-prefix-suffix2527/1



Approach - Check Notes. This code is only for the first part of KMP algo 

class Solution{
public:		

		
	int lps(string s)
	{
	  
	  int arr[s.length()];
	  int len=0;
	  int i=1;
	  arr[0]=0;
	  while(i<s.length())
	  {
	      if(s[i]==s[len])
	      {
	          len++;
	          arr[i]=len;
	          i++;
	      }
	      else{
	          if(len!=0)
	          {
	              len=arr[len-1];
	          }
	          else{
	              arr[i]=0;
	              i++;
	          }
	      }
	  }
	    return arr[s.length()-1];
	}
};