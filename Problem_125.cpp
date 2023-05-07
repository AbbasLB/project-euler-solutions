#include<bits/stdc++.h>
using namespace std;


bool checkPalin(long long n){
    string str=to_string(n);
    int i=0,j=str.size()-1;
    while(i<j)
    {
        if(str[i++]!=str[j--])
            return false;
    }
    return true;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    //int arr[]={0,1,2,3,4,5,6,7,8,9,10,11,12};
    //CombinationRepetition(arr,13,14);
    long long arr[10001];
    arr[0]=0;
    arr[1]=1;
    for(long long i=2;i<10001;i++)
        arr[i]=arr[i-1]+(i*i);
    set<long long> s;
    int pos=1;
    for(int i=1;i<10001;i++)
        for(int j=0;j<i-1;j++){
            long long diff=arr[i]-arr[j];
            if(diff<100000000 && checkPalin(diff)){
                s.insert(diff);
                cout<<pos++<<" "<<diff<<"\n";
            }

        }

    long long res=0;
    for(long long x:s)
        res+=x;

    cout<<res<<'\n';

    return 0;
}



