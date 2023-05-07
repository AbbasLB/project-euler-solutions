#include<bits/stdc++.h>
using namespace std;

long double power(long double n,long double e)
{
    long double res=1;
    for(int i=0;i<e;i++)
        res*=n;
    return res;
}
long double f(long double n)
{
    return 1-n+power(n,2)-power(n,3)+power(n,4)-power(n,5)+power(n,6)-power(n,7)+power(n,8)-power(n,9)+power(n,10);
}

long double testF(long double n)
{
    return n*n*n;
}

long double multMinus(int x,int rep)
{
    long double res=1;
    for(int i=1;i<=rep;i++)
        res*=(x-i);
    return res;
}

long double calcFIT(vector<long double> &coef,int x)
{
    long double res=0;
    for(int i=0;i<coef.size();i++)
        res+=coef[i]*multMinus(x,i);
    return res;
}

long double add_and_retrunFIT(vector<long double> &coef,int x,int y)
{
    long double newC=y;
    for(int i=0;i<coef.size();i++)
        newC-=coef[i]*multMinus(x,i);
    newC=newC/multMinus(x,coef.size());
    coef.push_back(newC);
    return calcFIT(coef,x+1);
}
long double solve()
{
    vector<long double> coef;
    long double res=0,tmp;
    for(int i=1;i<=10;i++)
    {
        tmp=add_and_retrunFIT(coef,i,f(i));
        res+=tmp;
        cout<<"FIT: "<<tmp<<'\n';
        cout<<"Correct: "<<f(i+1)<<"\n\n";
    }
    for(auto x:coef)
        cout<<x<<' ';
    cout<<'\n';

    return res;
}
int main() {
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
   //freopen("p102_triangles.txt","r",stdin);
    cout<<fixed<<setprecision(3)<<solve()<<'\n';
    return 0;
}
