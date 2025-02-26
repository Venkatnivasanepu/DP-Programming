// House Robber 2  :



#include<bits/stdc++.h>
using namespace std;
int maxi=0;
int minimaxi(int ind,vector<int>& pro,int flag)
{
    if(ind==pro.size() )
    {
        return 0;
    }
    if(flag == 0)
    {
         maxi = max(pro[ind]+minimaxi(ind + 1,pro,1),minimaxi(ind + 1,pro,0));
    }
    else
    {
        maxi=minimaxi(ind + 1 , pro , 0);
    }
    
    return maxi;
}

int main()
{
    int n;
    cin>>n;
    vector<int>pro;
    
   

    for(int i=0;i<n;i++)
    {
        int t;
        cin>>t;
        pro.push_back(t);
      
    }
    
    vector<int>arr1;
    for(int i=0;i<n-1;i++)
    {
        
        arr1.push_back(pro[i]);
    }
    vector<int>arr2;
    for(int i=1;i<n;i++)
    {
        
        arr2.push_back(pro[i]);
    }
    int res=minimaxi(0,arr1,0);
    int res1=minimaxi(0,arr2,0);
    
    
    cout<<max(res,res1)<<endl;
    return 0;
}