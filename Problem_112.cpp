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
        if(str[i]<str[i-1])
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

