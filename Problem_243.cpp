#include<bits/stdc++.h>
using namespace std;

#define MAX_N 1000000000


bool prime[MAX_N + 1];
vector<int> primes;
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
long long solveOptimized(long long n,int i,long long prod)
{
    if(prod>=n)
        return 0;
    long long ctr=1;
    for(;i<primes.size();i++){
        if(n%primes[i]!=0){
                if(prod*primes[i]<n)
                    ctr+=solveOptimized(n,i,prod*primes[i]);
                else break;
        }
    }
    return ctr;
}
long long solveOptimized(long long n)
{
    return solveOptimized(n,0,1);
}
long long solveNaive(long long n)
{
    long long res=0;
    for(long long i=1;i<n;i++)
        if(__gcd(i,n)==1)
            res++;
    return res;
}

bool check(long long num,long long deno)
{
    return num*94744<deno*15499;
}
int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    cout<<"Sieve...";
    SieveOfEratosthenes();
    cout<<"Finished\n";
    /*long double target=(long double)15499/94744;
    long long prod=1;
    for(long long i=0;i<10;i++){
        cout<<primes[i]<<' ';
        prod*=primes[i];
        cout<<prod<<' ';
        long long res=solveOptimized(prod);
        long double tmp=(long double)res/(prod-1);
        cout<<"res= "<<fixed<<setprecision(20)<<tmp;
        if(check(res,prod-1))
            cout<<" YES";
        cout<<'\n';
    }
    cout<<fixed<<setprecision(20)<<target<<'\n';
    */
    long long add=2,prev=2;
    long double tmp,mn=10;
    for(long long i=4;i<=6469693230;i+=add){
        //cout<<i<<' ';
        long long res=solveOptimized(i);
        tmp=(long double)res/(i-1);
        if(tmp<mn){
            add=i-prev;
            prev=i;
            mn=tmp;
            cout<<"res= "<<res<<"/"<<i<<" = "<<fixed<<setprecision(20)<<tmp;
        }
        if(check(res,i-1)){
                cout<<i<<" YES\n";
                break;
        }
        cout<<'\n';
    }
    return 0;
}



