#include<bits/stdc++.h>
using namespace std;


int main(){
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);cout.tie(0);
    vector<pair<int,vector<set<int>>>> v(201);
    for(auto &x:v)
        x.first=INT_MAX;
    set<int> tmpS;
    tmpS.insert(1);
    vector<set<int>> tmpV;
    tmpV.push_back(tmpS);
    v[1]=make_pair(0,tmpV);
    for(int i=1;i<201;i++)
    {
        for(auto cutSet:v[i].second)
        for(int x:cutSet)
        if(i+x<201){
            if(v[i].first+1<v[i+x].first){
                set<int> tmp=cutSet;
                tmp.insert(i);
                tmp.insert(i+x);
                vector<set<int>> tmp2;
                tmp2.push_back(tmp);
                v[i+x]=make_pair(v[i].first+1,tmp2);
            }else if(v[i].first+1==v[i+x].first){
                set<int> tmp=cutSet;
                tmp.insert(i);
                tmp.insert(i+x);
                (v[i+x].second).push_back(tmp);
            }
        }
    }
    long long res=0;
    for(int i=1;i<201;i++){
        cout<<"i="<<i<<" res="<<v[i].first<<'\n';
        res+=v[i].first;
    }
    cout<<res<<'\n';


    return 0;
}



