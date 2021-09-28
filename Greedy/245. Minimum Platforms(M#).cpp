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