#include<bits/stdc++.h>
using namespace std;

bool isInc(int n)
{
    if(n<100)
        return 1;
    string str=to_string(n);
    for(int i=1;i<str.size();i++)
        if(str[i]>str[i-1])
            return 0;
    return 1;
}
bool isDec(int n)
{
    if(n<100)
        return 1;
    string str=to_string(n);
    for(int i=1;i<str.size();i++)
        if(str[i]<str[i-1])#include<bits/stdc++.h>
using namespace std;

long long fact(long long n);

long long nCr(long long n, long long r)
{
    return fact(n) / (fact(r) * fact(n - r));
}

// Returns factorial of n
long long fact(long long n)
{
    long long res = 1;
    for (long long i = 2; i <= n; i++)
        res = res * i;
    return res;
}



long long solveHelper(long long r)
{
    if(r==0)
        return 0;
    long long n=9;
    return nCr(r+n-1,r);
}
long long solveZeros(long long r)
{
    long long res=0;
    for(int i=1;i<r;i++)
        res+=solveHelper(i);
    return res;
}

long long solveExactlyR(long long n)
{
    return 2*solveHelper(n)+solveZeros(n)-10;
}
long long solve(long long n)
{
    long long res=0;
    for(int i=1;i<=n;i++){
        res+=solveExactlyR(i);
        cout<<i<<" "<<solveExactlyR(i)<<'\n';
    }
    return res+n;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);

    cout<<solve(10)<<'\n';
    return 0;
}
 /*long long cnt=0;
    for(int i=1;i<100000;i++)
    {
        if(isInc(i) || isDec(i))
            cnt++;
    }
    cout<<cnt<<'\n';
bool isInc(int n)
{
    if(n<100)
        return 1;
    string str=to_string(n);
    for(int i=1;i<str.size();i++)
        if(str[i]>str[i-1])
            return 0;
    return 1;
}
bool isDec(int n)
{
    if(n<100)
        return 1;
    string str=to_string(n);
    for(int i=1;i<str.size();i++)
        if(str[i]<str[i-1])
            return 0;
    return 1;
}*/

            return 0;
    return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long long cnt=0;
    long double res;
    for(int i=1;i<10000000;i++)
    {
        if(!isInc(i) && !isDec(i))
            cnt++;
        res=(long double)cnt*100/i;
        if(res==99)
        {
            cout<<"At "<<i<<": "<<res<<"%\n";
        }

    }
    return 0;


}

