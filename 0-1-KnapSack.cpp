#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void dynamic(int wt[],int val[],int N,int W){
    // N is number of Itesm and W is the max weight capacity
    int dp[N+1][W+1];
    for(int i=0;i<N+1;i++){
        dp[i][0]=0;
    }
    for(int j=0;j<W+1;j++){
        dp[0][j]=0;
    }
    for(int i=1;i<=N;i++){
        for(int j=1;j<=W;j++){
            // Can Include the I'th item only when it less than max capacity
            if(wt[i-1]<=j){
                // Remeber Index MisMatch 
                dp[i][j]=max(val[i-1]+dp[i-1][j-wt[i-1]],dp[i-1][j]);
            }
        }
    }
    cout<<dp[N][W]<<endl;
}


int main()
{
    int val[] = {60, 100, 120}; 
    int wt[] = {10, 20, 30}; 
    int n = sizeof(val)/sizeof(val[0]); 
    dynamic(wt,val,n,50);
    return 0;
}
