// House Robber :



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
    

    int res=minimaxi(0,pro,0);
    
    cout<<res<<endl;
    return 0;
}