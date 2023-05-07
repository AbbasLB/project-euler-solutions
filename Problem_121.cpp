#include<bits/stdc++.h>
using namespace std;

long long deno(int n)
{
    long long res=1;
    for(int i=1;i<=n;i++)
        res*=i+1;
    return res;
}

long long numer(int n)
{
    long long res=0;
    int mnBlue=(n/2)+1;
    for(int i=0;i<(1<<n);i++)
    {
        if(__builtin_popcount(i)>=mnBlue)
        {
            long long cur=1,pos=1;
            for(int j=1;j<(1<<n);j=j<<1,pos++){
                if((i&j)==0)
                    cur*=pos;
            }
            res+=cur;
        }
    }
    return res;
}
void solve(int n)
{
    cout<<"numer="<<numer(n)<<'\n';
    cout<<"deno="<<deno(n)<<'\n';
    cout<<"prize="<<deno(n)/numer(n)<<'\n';

}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    solve(15);

    return 0;
}



