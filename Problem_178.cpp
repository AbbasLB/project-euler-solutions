#include<bits/stdc++.h>
using namespace std;


long long dp[10][41][1<<11];
long long solve(int a0, int n,int mask)
{
    if(dp[a0][n][mask]!=-1)
        return dp[a0][n][mask];
    if(n==1)
        return (mask|(1<<a0))==((1<<10)-1);
    if(a0==0)
        return dp[a0][n][mask]=solve(1,n-1,mask|1);
    if(a0==9)
        return dp[a0][n][mask]=solve(8,n-1,mask|(1<<9));
    return dp[a0][n][mask]=solve(a0-1,n-1,mask|(1<<a0))+solve(a0+1,n-1,mask|(1<<a0));
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    memset(dp,-1,sizeof(dp));
    long long res=0;
    for(int sz=10;sz<=40;sz++)
        for(int i=1;i<10;i++)
            res+=solve(i,sz,0);
    cout<<res<<'\n';
    return 0;



}

