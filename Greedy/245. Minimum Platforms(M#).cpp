Question: https://practice.geeksforgeeks.org/problems/minimum-platforms-1587115620/1

Solution: 

int findPlatform(int arr[], int dep[], int n)
{
    vector < pair<int,int> > T;
    for(int i=0;i<n;i++){
        T.push_back(make_pair(arr[i],dep[i]));
    }
    sort(T.begin(),T.end());    //sort in ascending order of arrival time as it is first elememt in pair
    
    int slots[10000];
    for(int i=0;i<n;i++){
        slots[i]=-1;
    }
    
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(slots[j]<T[i].first){    //if current arrival time is more than the last departure time of the platform then we assign this platform to the train
                slots[j]=T[i].second;   
                break;
            }
        }
    }
    
    int count=0;
    for(int i=0;i<n;i++){
        if(slots[i]!=-1)
            count++;
    }
    
    return count;
}



//Second Approach with priority queue with TC - O(nlogn)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
    	if(n == 1)
    	    return 1;
    	// Your code here
    	vector<pair<int,int>>v;
    	
    	for(int i=0;i<n;i++){
    	    v.push_back({arr[i], dep[i]});
    	}
    	sort(v.begin(), v.end());  //Sort based on arrival time
    	
    	
    	priority_queue<int, vector<int>, greater<int>> pq;
    	pq.push(v[0].second);
    	int count = 1;   //number of platforms
    	
    	for(int i = 1;i<n;i++){
    	    
    	    while(!pq.empty() && pq.top() < v[i].first)  //remove the trains whose departure time is earlier than the arrival time of the current train
    	        pq.pop();
    	        
    	    if(pq.size() < count){  //Check if there is any empty station
    	        pq.push(v[i].second);
    	    }else{   //If not then increase the number of station
    	        count++;
    	        pq.push(v[i].second);
    	    }
    	}
    	
    	return count;
    }
};