#include<bits/stdc++.h>
using namespace std;

long long  mx(long long a)
{
    long long square=a*a;
    unordered_map<int,unordered_map<int,bool>> arr;
   // vector<bool> v(square,0);
    long long  a1 = a-1,a2=a+1;
    long long  tmp1=1,tmp2=1,mod;
    long long  mx=-1;
    while(tmp1>0 && tmp2>0)
    {

        if(arr[tmp1][tmp2])
            break;
        mod=(tmp1%square+tmp2%square)%square;
        if(mod>mx)
            mx=mod;
        arr[tmp1][tmp2]=1;
        tmp1=(tmp1*a1)%square;
        tmp2=(tmp2*a2)%square;
    }
    return mx;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    long long res=0;
    for(int i=3;i<1001;i++){
        res+=mx(i);
    }
    cout<<res<<'\n';

    return 0;
}



