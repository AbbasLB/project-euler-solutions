#include<bits/stdc++.h>
using namespace std;

#define MAX_N 100000000

vector<long long> primes;

bool prime[MAX_N + 1];
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
    int res=0;
    for (int p = 2; p <= MAX_N; p++)
        if (prime[p])
            primes.push_back(p);
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    SieveOfEratosthenes();
    long long tmp;
    long long res=0;
    for(int i=0;i<primes.size();i++)
        for(int j=0;j<=i;j++){
                tmp=primes[i]*primes[j];
                if(tmp>=1e8)
                    break;
                res++;
        }
    cout<<res<<'\n';

    return 0;
}



