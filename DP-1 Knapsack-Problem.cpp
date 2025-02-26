// 0/1 Knapsack Problem :



#include<bits/stdc++.h>
using namespace std;
int maxi=0;
int minimaxi(int ind,vector<int>& pro,vector<int>& wt,int wet)
{
    if(ind==pro.size() || wet == 0)
    {
        return 0;
    }
    if(wt[ind]<=wet)
    {
         maxi = max(pro[ind]+minimaxi(ind+1,pro,wt,wet-wt[ind]),minimaxi(ind+1,pro,wt,wet));
    }
    else
    {
        maxi=minimaxi(ind+1,pro,wt,wet);
    }
    
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int>pro,wt;
    
    int  wet;
    cin>>wet;
    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        pro.push_back(t);
      
    }
    for(int i=0;i<n;i++)
    {
        int k;
        cin>>k;
      
        wt.push_back(k);
    }
    

    int res=minimaxi(0,pro,wt,wet);
    
    cout<<res<<endl;
    return 0;
}