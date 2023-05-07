#include<bits/stdc++.h>
using namespace std;

bool isPrime(long long n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;


    for (int i = 5; i  <= (long double)sqrt(n)+100; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    string s="1111111111";
    string tmp;

    long long ans=0;

    long long num;
    for(int rep=0;rep<10;rep++)
    {
        long long res=0;
        for(int i=0;i<10;i++)
            s[i]='0'+rep;
        for(int i=0;i<10;i++)
        {
            for(int j=0;j<10;j++)
            {
                tmp=s;
                tmp[i]='0'+j;
                num=stoll(tmp);
                //if(rep==3)
                //    cout<<num<<'\n';
                if(num>1000000000 && isPrime(num)){
                     res+=num;
                     //cout<<num<<'\n';
                }

            }
        }
        cout<<rep<<' '<<res<<'\n';
        ans+=res;
    }
    long long res0=0,res2=0,res8=0,num0,num2,num8;
     string s0="0000000000",tmp0;
     string s2="2222222222",tmp2;
     string s8="8888888888",tmp8;
    for(int a=0;a<10;a++)
    for(int b=a+1;b<10;b++)
    for(int c=0;c<10;c++)
    for(int d=0;d<10;d++)
    {
        tmp0=s0;
        tmp0[a]='0'+c;
        tmp0[b]='0'+d;
        tmp2=s2;
        tmp2[a]='0'+c;
        tmp2[b]='0'+d;
        tmp8=s8;
        tmp8[a]='0'+c;
        tmp8[b]='0'+d;
        num0=stoll(tmp0);
        num2=stoll(tmp2);
        num8=stoll(tmp8);
        if(num0>1000000000 && isPrime(num0)){
            //cout<<num0<<'\n';
            res0+=num0;
        }
        if(num2>1000000000 && isPrime(num2)){
            //cout<<num2<<'\n';
            res2+=num2;
        }
        if(num8>1000000000 && isPrime(num8)){
            //cout<<num8<<'\n';
            res8+=num8;
        }
    }
    cout<<"res0:"<<res0<<'\n';
    cout<<"res2:"<<res2<<'\n';
    cout<<"res8:"<<res8<<'\n';
    ans=ans+res0+res2+res8;
    cout<<ans<<'\n';
    return 0;
}

