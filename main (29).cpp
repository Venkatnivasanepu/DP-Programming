#include<bits/stdc++.h>
using namespace std;



int intmini(int n, int ind,int sum,int target, vector<int>&arr,vector<int>&arr1, vector<vector<int>>&dp)
{   
    
    // if(sum==target)
    // {
    //     return 0;
    // }
    // if(ind == n || sum>target)
    // {
    //     return 1e8;
    // }
    // if(dp[ind][sum]!=-1)
    // {
    //     return dp[ind][sum];
    // }
    
    // int pick = 1e8, notpick = 1e8;
    
    // pick = min((pick), 1+ intmini(n,ind,cnt,sum+arr[ind] ,target,arr,dp));
    
    // notpick = min((notpick), intmini(n,ind+1,cnt,sum ,target,arr,dp));
    // // int mini=min(intmini(n,ind,cnt+1,sum+arr[ind],target,arr),intmini(n,ind+1,cnt,sum,target,arr));
    
    
    // return dp[ind][sum]=min(pick,notpick);
    if(ind == n)
    {
        if(sum<=target)
        {
        return 0;
        }
    }
    if(sum>target || ind > n)
    {
        return INT_MIN;
    }
    if(dp[ind][sum]!=-1)
    {
        return dp[ind][sum];
    }
    int pick=INT_MIN,npick=INT_MIN;
    pick=max(pick,arr1[ind]+intmini(n,ind+1,sum+arr[ind] ,target,arr,arr1,dp));
    npick=max(pick,intmini(n,ind+1,sum,target,arr,arr1,dp));
    
    return dp[ind][sum]=max(pick,npick);
    
}

int main()
{
    int n,target;
    cin>>n>>target;
    vector<int>arr(n);
    vector<int>arr1(n);
    
    vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    for(int i=0;i<n;i++)
    {
        cin>>arr1[i];
    }
    int res= intmini(n,0,0,target,arr,arr1,dp);
    cout<<res<<endl;
    return 0;
}