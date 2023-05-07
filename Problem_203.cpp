#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000000

bool prime[MAX_N + 1];
vector<long long> primes;
void SieveOfEratosthenes()
{
    memset(prime, true, sizeof(prime));

    for (int p = 2; p * p <= MAX_N; p++)
    {
        if (prime[p] == true)
        {
            for (int i = p * p; i <= MAX_N; i += p)
                prime[i] = false;
        }
    }
    for (int p = 2; p <= MAX_N; p++)
        if (prime[p])
           primes.push_back(p);
}

long long nCrModp(__int128 n, __int128 r, __int128 p)
{
    if (r > n - r)
        r = n - r;
    __int128 C[r + 1];
    memset(C, 0, sizeof(C));

    C[0] = 1;
    for (__int128 i = 1; i <= n; i++) {
        for (__int128 j = min(i, r); j > 0; j--)
            C[j] = (C[j] + C[j - 1]) % p;
    }
    return (long long)C[r];
}

bool squareFree(long long n)
{
    for(int i=0;i<primes.size();i++)
        if(n%(primes[i]*primes[i])==0)
            return 0;
    return 1;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    SieveOfEratosthenes();
    set<long long> s;
    for(int n=1;n<51;n++)
    {
        for(int r=0;r<=(n/2);r++){
            s.insert(nCrModp(n,r,1e18));
        }
    }
    long long num=0,res=0;
    for(long long x:s){
        if(squareFree(x)){
            res+=x;
            num++;
        }

    }
    cout<<num<<'\n';
    cout<<res<<'\n';
    return 0;
}



