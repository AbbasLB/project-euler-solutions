#include<bits/stdc++.h>
using namespace std;

#define MAXN   100000003

bool prime[MAXN + 1];
void SieveOfEratosthenes()
{
    int n=MAXN;
    memset(prime, true, sizeof(prime));
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= n; i += p)
                prime[i] = false;
        }
    }
}

bool check(int n)
{
    int d1,d2;
    for(int i=1;i<=sqrt(n)+2;i++)
    {

        if(n%i==0)
        {
            d1=i;
            d2=n/i;
            if(!prime[d1+n/d1] || !prime[d2+n/d2])
                return 0;
        }
    }
    return 1;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    SieveOfEratosthenes();
    long long res=0;
    for(int i=2;i<=100000001;i++)
        if(prime[i] && check(i-1))
            res+=i-1;
           // cout<<i-1<<"\n";
    cout<<res<<'\n';

    return 0;


}

