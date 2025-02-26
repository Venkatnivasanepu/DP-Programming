#include <bits/stdc++.h>
using namespace std;
int MOD=1000000007;
int maxpath(int n,int i,int j,vector<vector<char>> &arr,vector<vector<int>> &dp)
{
  if(i==n-1 && j==n-1)
  {
    return 1;
  }
  if((i>n-1|| j>n-1)|| ( (arr[i][j]=='*') ))
  {
    return 0;
  }
  if(dp[i][j]!=-1)
  {
    return dp[i][j];
  }
  return dp[i][j]=(maxpath(n,i+1,j,arr,dp)%MOD+maxpath(n,i,j+1,arr,dp)%MOD)%MOD;
  
}

int main() 
{
   int n;
   cin>>n;
   vector<vector<char>>arr(n);
   vector<vector<int>>dp(n,vector<int>(n,-1));
   for(int i=0;i<n;i++)
   {
     for(int j=0;j<n;j++)
     {
       char ch;
       cin>>ch;
       arr[i].push_back(ch);
     }
   }
   int res=maxpath(n,0,0,arr,dp);
   cout<<res<<endl;
   
    return 0;
}