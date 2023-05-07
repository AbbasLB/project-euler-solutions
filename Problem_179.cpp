#include<bits/stdc++.h>
using namespace std;

#define MAXN   100000002

int spf[MAXN];
void sieve()
{
    spf[1] = 1;
    for (int i=2; i<MAXN; i++)
        spf[i] = i;
    for (int i=4; i<MAXN; i+=2)
        spf[i] = 2;

    for (int i=3; i*i<MAXN; i++)
    {
        if (spf[i] == i)
        {
            for (int j=i*i; j<MAXN; j+=i)
                if (spf[j]==j)
                    spf[j] = i;
        }
    }
}
int getNumDivisors(int x)
{
    int res=1;
    int tmp=0;
    int cur=spf[x];
    while (x != 1)
    {
        if(spf[x]==cur)
            tmp++;
        else {
            res*=tmp+1;
            tmp=1;
            cur=spf[x];
        }
        x = x / spf[x];
    }
    res*=tmp+1;
    return res;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    sieve();
    int res=0;
    for(int i=2;i<10000000;i++)
        if(getNumDivisors(i)==getNumDivisors(i+1))
            res++;
    cout<<res<<'\n';
    return 0;
}
