#include<bits/stdc++.h>
using namespace std;

vector<int> split(string str)
{
    vector<int> vect;
    stringstream ss(str);
    for (int i; ss >> i;) {
        vect.push_back(i);
        if (ss.peek() == ',')
            ss.ignore();
    }
    return vect;
}

int sum(vector<int> &v)
{
    int res=0;
    for(int i=0;i<v.size();i++)
        res+=v[i];
    return res;
}
int sum(vector<int> &v,int mask)
{
    int res=0;
    for(int i=0;i<v.size();i++)
        if(mask&(1<<i))
            res+=v[i];
    return res;
}

bool checkSetHelper(vector<int> &v,int maskS1)
{
    int sumS1,sumS2,szS1,szS2;
    int n=v.size();
    for(int maskS2=1;maskS2<(1<<n);maskS2++){

        if((maskS1&maskS2)==0)
        {
            sumS1=sum(v,maskS1);
            sumS2=sum(v,maskS2);
            szS1=__builtin_popcount(maskS1);
            szS2=__builtin_popcount(maskS2);
            if(sumS1==sumS2 ||(szS1>szS2 && sumS1<=sumS2) || (szS1<szS2 && sumS1>=sumS2))
                return 0;
        }
    }
    return 1;73702
}
bool checkSet(vector<int> &v)
{
    bool res=1;
    int n=v.size();
    for(int maskS1=1;maskS1<(1<<n);maskS1++)
        if(!checkSetHelper(v,maskS1)){
            res=0;
            break;
    }
    return res;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("p105_sets.txt","r",stdin);
    string str;

    int res=0,sumOfSet;
    int setNum=1;
    bool isSpecial=0;
    while(cin>>str)
    {
        vector<int> v=split(str);
        sumOfSet=sum(v);
        isSpecial=checkSet(v);
        cout<<"Set "<<setNum<<": isSpecial="<<isSpecial<<" Sum(A)="<<sumOfSet<<'\n';
        if(isSpecial)
            res+=sumOfSet;
        setNum++;
    }
    cout<<res<<'\n';
    return 0;
}

