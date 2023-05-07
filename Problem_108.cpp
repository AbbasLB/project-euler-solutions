#include<bits/stdc++.h>
using namespace std;

long long check(long long n,long long y)
{
    if(-n*y/(n-y)>0 && ((n*y)%(n-y))==0)
        return -(n*y)/(n-y);
    return -1;
}
long long solve(long long n)
{
    set<pair<long long,long long>> s;
    for(long long y=n+1;y<2*n+2;y++)
    {
        long long x=check(n,y);
        if( x!=-1 && !s.count(make_pair(x,y)) && !s.count(make_pair(y,x)))
            s.insert(make_pair(x,y));
    }
    return s.size();

}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    //for(int i=1;i<101;i++)
    //    cout<<i<<" "<<solve(i)<<'\n';
    //cout<<210<<" "<<solve(210)<<'\n';
    //cout<<2310<<" "<<solve(2310)<<'\n';
    long long mx=-1;
    for(int i=2;i<510510;i+=2)
    {
        long long tmp=solve(i);
        if(tmp>mx)
        {
            cout<<i<<' '<<tmp<<'\n';
            mx=tmp;
        }


    }
    cout<<510510<<" "<<solve(510510)<<'\n';
    return 0;
}
