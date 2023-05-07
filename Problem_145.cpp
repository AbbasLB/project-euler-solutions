#include<bits/stdc++.h>
using namespace std;


bool check(int n){
    if(n%10==0)
        return 0;
    string str=to_string(n);
    reverse(str.begin(),str.end());
    str=to_string(stoi(str)+n);
    for(int i=0;i<str.size();i++)
        if(((str[i]-'0')&1)==0)
            return false;
    return true;
}


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    int res=0;
    for(int i=1;i<1000000000;i++){
        res+=check(i);
    }

    cout<<res<<'\n';
    return 0;
}



