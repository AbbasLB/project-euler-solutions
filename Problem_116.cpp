#include<bits/stdc++.h>
using namespace std;


long long dp[100001][10];
long long solve(long long sz,int minLen)
{
    if(sz<minLen)
        return 1;
    if(dp[sz][minLen]!=-1)
        return dp[sz][minLen];
    long long res=1;
    for(long long i=0;i<=sz-minLen;i++)
            res+= solve(sz - i - minLen,minLen);
    return dp[sz][minLen]=res;
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("p105_sets.txt","r",stdin);
    memset(dp, -1, sizeof(dp));

    cout<<solve(50,2)+solve(50,3)+solve(50,4)-3<<'\n';
    return 0;
}
