#include<bits/stdc++.h>
using namespace std;


long long dp[100001];
long long solve(long long sz)
{
    if(sz<50)
        return 1;
    if(dp[sz]!=-1)
        return dp[sz];
    long long res=1;
    for(long long i=0;i<=sz-50;i++)
        for(long long len=50;len<=sz-i;len++)
        {
                res+= solve(sz - i - len - 1);
        }
    return dp[sz]=res;
}


int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //freopen("p105_sets.txt","r",stdin);
    memset(dp, -1, sizeof(dp));
    for(int i=2;i<100000;i++)
    {
        if(solve(i)>=1000000)
        {
            cout<<"solve("<<i<<")="<<solve(i)<<'\n';
            break;

        }

    }
    return 0;
}
