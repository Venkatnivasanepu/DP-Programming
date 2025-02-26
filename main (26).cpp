#include<bits/stdc++.h>
using namespace std;



int intmini(int n, int ind,int cnt,int sum,int target, vector<int>&arr, vector<vector<int>>&dp)
{   
    
    if(sum==target)
    {
        return 0;
    }
    if(ind == n || sum>target)
    {
        return 1e8;
    }
    if(dp[ind][sum]!=-1)
    {
        return dp[ind][sum];
    }
    
    int pick = 1e8, notpick = 1e8;
    
    pick = min((pick), 1+ intmini(n,ind,cnt,sum+arr[ind] ,target,arr,dp));
    
    notpick = min((notpick), intmini(n,ind+1,cnt,sum ,target,arr,dp));
    // int mini=min(intmini(n,ind,cnt+1,sum+arr[ind],target,arr),intmini(n,ind+1,cnt,sum,target,arr));
    
    
    return dp[ind][sum]=min(pick,notpick);
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int res= intmini(n,0,0,0,target,arr,dp);
    if(res==0)
    {
        cout<<-1<<endl;
    }
    else
    {
        cout<<res<<endl;
    }
    return 0;
}