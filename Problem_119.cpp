#include<bits/stdc++.h>
using namespace std;


long long getSum(long long n){
    string s=to_string(n);
    long long sum=0;
    for(int i=0;i<s.size();i++)
        sum+=(s[i]-'0');
    return sum;
}

int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    set<long long> s;
    for(int i=2;i<163;i++)
    {
        long long tmp=i;
        while(tmp>0)
        {
            if(tmp>10 && getSum(tmp)==i){
                //cout<<"num="<<tmp<<" i="<<i<<" power="<<checkPow(i,tmp)<<'\n';
                s.insert(tmp);
            }
            tmp*=i;
        }
    }
    int i=1;
    for(auto x:s)
        cout<<i++<<" "<<x<<'\n';
    return 0;
}

/*long long checkPow(long long sum,long long n)
{
    long long  num=1;
    if(sum==1)
        return -1;
    long long tmp=sum;
    while(tmp<n)
        tmp*=sum,num++;
    if(tmp==n)
        return num;
    return -1;
}
*/
