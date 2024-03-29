https://practice.geeksforgeeks.org/problems/merge-two-sorted-arrays5135/1


Approach - refer notes
TC - O(nlogn  + mlogm)
SC - O(1)


class Solution{
public:
	void merge(int one[], int two[], int sizeOne, int sizeTwo) {
	    // code here
	     int i=sizeOne-1, j = 0;
        while(i>=0 and j<sizeTwo){
            if(one[i]>two[j])
            {
                swap(one[i],two[j]);
                 i--,j++;
            }
            else        
                break;
           
        }
        sort(one,one+sizeOne);
        sort(two,two+sizeTwo);
	}
};