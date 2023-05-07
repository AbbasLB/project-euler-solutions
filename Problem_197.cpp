#include<bits/stdc++.h>
using namespace std;


long double f(long double x)
{
    return floor(pow(2,(long double)30.403243784-x*x))*1e-9;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    long double a=-1,res;

    for(int i=0;i<1000000;i++)
    {
        //cout<<"U["<<i<<"]= "<<a<<'\n';
        a=f(a);
    }
    res=a;
    a=f(a);
    res+=a;
    cout<<setprecision(12)<<res<<'\n';


    return 0;


}

