#include<bits/stdc++.h>
using namespace std;
#define MAXN   100001

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
long long getRad(long long x)
{
    unordered_set<long long> s;
    while (x != 1)
    {
        s.insert(spf[x]);
        x = x / spf[x];
    }
    long long res=1;
    for(auto x:s)
        res*=x;
    return res;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    sieve();
    vector<pair<long long,long long>> v;
    for(long long i=1;i<=100000;i++)
        v.push_back(make_pair(getRad(i),i));
    sort(v.begin(),v.end());
    cout<<v[9999].second;


    return 0;
}



