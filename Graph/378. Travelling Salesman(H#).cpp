//Recursively find all possible path and choose the best one. Optimize using memoizaton
//TC - O(2^n * n) => dimension of the dp array

#include<iostream>
using namespace std;

#define INT_MAX 999999

int n=4;
int dist[10][10] = {
        {0,20,42,25},
        {20,0,30,34},
        {42,30,0,10},
        {25,34,10,0}
};
int VISITED_ALL = (1<<n) -1;

int dp[16][4];


int  tsp(int mask,int pos){  //mask represent the visited cities, pos is the current city where we are
                            //mask = 0101(in binary)=5(in decimal) means city 0 and city 2 are visied, rest are unvisited 
	
	if(mask==VISITED_ALL){
		return dist[pos][0];
	}
	if(dp[mask][pos]!=-1){
	   return dp[mask][pos];
	}

	//Now from current node, we will try to go to every other node and take the min ans
	int ans = INT_MAX;

	//Visit all the unvisited cities and take the best route
	for(int city=0;city<n;city++){

		if((mask&(1<<city))==0){

			int newAns = dist[pos][city] + tsp( mask|(1<<city), city);
			ans = min(ans, newAns);
		}
	}

	return dp[mask][pos] = ans;
} 

int main(){
    /* init the dp array */
    for(int i=0;i<(1<<n);i++){
        for(int j=0;j<n;j++){
            dp[i][j] = -1;
        }
    }


	cout<<"Travelling Saleman Distance is "<<tsp(1,0);  //we start with the first city, so mask is 1 initially. Our goal is to reach back to 1 again visiting all other cities once. Instead of first city we can take any other city as our inital and final destination, as asnwer will always be same.
    return 0;
}
